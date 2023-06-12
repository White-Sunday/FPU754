import copy
# generate nxn wallace_tree with number n
# 每层的sn，cn难以做到准确设置字宽，这里统一设置，代码生成后可以手动消除冗余
# 由于代码实现逻辑比较简单，故在wllacetree左边有一定数量的csa冗余，代码生成后可以手改进、消除冗余csa
# 同时,使用c_overflow来存放最高位csa产生的进位溢出，可以当成冗余优化掉
n = 26
m = 24
code_str = ""
'''
开头这段自己改写，程序会生成后面的代码
input [7:0] a;	// input a
input [7:0] b;	// input b
output [15:5] x;	// sum high
output [15:5] y;	// carry high
output [4:0] z;	// sum low

reg [7:0] p [7:0];	// p[i][j]
parameter zero  = 1'b0;	// constant 0
integer i,j;
always @ * begin
    for(i=0;i<8;i=i+1)
        for(j=0;j<8;j=j+1)
            p[i][j] = a[i]&b[j];	// p[i][j]=a[i]&b[j]	
end

wire [0:0] c_overflow;  // storing the carry_out of highest level csa
'''

# init level 1
level_num = 0
level_csa_max_num = m//3 + (m%3)//2
input_list = []
input_next_level_list = []
for i in range(n+m):
    input_list.append([])
    input_next_level_list.append([])

for i in reversed(range(n+m)):
    for j in reversed(range(m)):
        if i-j < n and i-j >= 0:
            input_list[i].append("p[{0}][{1}]".format(i-j,j))

# print the input_list for debug
# for i in reversed(range(n+m)):
#     for item in input_list[i]:
#         print("{}:".format(i)+item)

level_num += 1
code_str += "// level {0}\n".format(level_num)
code_str += "wire [{0}:0] s{1} [{2}:{3}];\n".format(level_csa_max_num-1, level_num, n+m-1,level_num)
code_str += "wire [{0}:0] c{1} [{2}:{3}];\n".format(level_csa_max_num-1, level_num, n+m-1,level_num+1)
for i in reversed(range(n+m)):
    if len(input_list[i])==0:
        code_str += "// {0}:\n".format(i)
    else:
        csa_num = len(input_list[i])//3 + len(input_list[i])%3//2
        for csa_i in reversed(range(csa_num)):
            if len(input_list[i]) > 2:
                buffer_input = []
                buffer_input.append(input_list[i][0])
                input_list[i].pop(0)
                buffer_input.append(input_list[i][0])
                input_list[i].pop(0)
                buffer_input.append(input_list[i][0])
                input_list[i].pop(0)
                code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                    .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],buffer_input[2],\
                    "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
                input_next_level_list[i+1].append("c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
            else:
                buffer_input = []
                buffer_input.append(input_list[i][0])
                input_list[i].pop(0)
                buffer_input.append(input_list[i][0])
                input_list[i].pop(0)
                code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                    .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],"zero",\
                    "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
                input_next_level_list[i+1].append("c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
        if len(input_list[i]) == 1:
            code_str += "// {0}: {1}\n".format(i, input_list[i][0])
            input_next_level_list[i].insert(0,input_list[i][0])

while 1:
    # init input_list and input_next_level_list
    input_list = copy.deepcopy(input_next_level_list)
    input_next_level_list = []
    for i in range(n+m):
        input_next_level_list.append([])
    
    level_num += 1
    input_list_max_num = 0
    for i in range(n+m):
        if input_list_max_num < len(input_list[i]):
            input_list_max_num = len(input_list[i])

    if input_list_max_num == 2:
        break

    level_csa_max_num = input_list_max_num//3 + (input_list_max_num%3)//2
    code_str += "// level {0}\n".format(level_num)
    code_str += "wire [{0}:0] s{1} [{2}:{3}];\n".format(level_csa_max_num-1, level_num, n+m-1, level_num)
    code_str += "wire [{0}:0] c{1} [{2}:{3}];\n".format(level_csa_max_num-1, level_num, n+m-1, level_num+1)
    for i in reversed(range(n+m)):
        if len(input_list[i])==0:
            code_str += "// {0}:\n".format(i)
        else:
            csa_num = len(input_list[i])//3 + len(input_list[i])%3//2
            for csa_i in reversed(range(csa_num)):
                if len(input_list[i]) > 2:
                    buffer_input = []
                    buffer_input.append(input_list[i][0])
                    input_list[i].pop(0)
                    buffer_input.append(input_list[i][0])
                    input_list[i].pop(0)
                    buffer_input.append(input_list[i][0])
                    input_list[i].pop(0)
                    if i < n+m-1:
                        code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                            .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],buffer_input[2],\
                            "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                        input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
                        input_next_level_list[i+1].append("c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                    else:
                        code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                            .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],buffer_input[2],\
                            "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c_overflow")
                        input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
                else:
                    buffer_input = []
                    buffer_input.append(input_list[i][0])
                    input_list[i].pop(0)
                    buffer_input.append(input_list[i][0])
                    input_list[i].pop(0)
                    if i < n+m-1:
                        code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                            .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],"zero",\
                            "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                        input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
                        input_next_level_list[i+1].append("c{0}[{1}][{2}]".format(level_num, i+1, csa_i))
                    else:
                        code_str += "csa a{0}_{1}_{2} ({3},{4},{5},{6},{7});\n"\
                            .format(level_num,i,csa_i,buffer_input[0],buffer_input[1],"zero",\
                            "s{0}[{1}][{2}]".format(level_num, i, csa_i), "c_overflow")
                        input_next_level_list[i].insert(0,"s{0}[{1}][{2}]".format(level_num, i, csa_i))
            if len(input_list[i]) == 1:
                code_str += "// {0}: {1}\n".format(i, input_list[i][0])
                input_next_level_list[i].insert(0,input_list[i][0])

code_str += "\n"
for i in reversed(range(n+m)):
    if len(input_list[i]) == 2:
        code_str += "assign x[{0}] = {1}; assign y[{0}] = {2};\n".format(i,input_list[i][0],input_list[i][1]) 
    else:
        code_str += "assign z[{0}] = {1};\n".format(i,input_list[i][0])

print(code_str)
