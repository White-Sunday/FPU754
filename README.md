# FPU754_wh
这是一个学习目的项目,代码来自于教材,针对部分细节做了修改:
Yamin Li - Computer Principles and Design in Verilog HDL-Wiley (2015)

基于教材内容,我使用Verilator工具成功复现基本的32位浮点数运算:
- 整数浮点数相互转换
- 浮点数加、减法运算(流水与非流水)
- 浮点数乘法运算(流水与非流水)
- 浮点数除法运算

除此之外，比较有意义的工作是：
使用python实现了一个wallacetree生成工具，可以生成指定nxn、nxm wallacetree的verilog代码。
生成策略中以粒度较小的单个csa为单位来构建wallacetree，只在高位部分存在部分csa冗余。
同时为了编程方便，level间的sn、cn的字宽设置也有一定冗余。
以上冗余有经验的设计者均可以微调消除。

需要注意的是，我对代码细节有两处疑惑，仍在阅读754-1985,754-2008进行考证中：
1.nan小数部分的生成策略标准是否有过相关规定
wire [22:0] nan_frac = ({1'b0,a[22:0]}>{1'b0,b[22:0]})? {1'b1,a[21:0]} : {1'b1,b[21:0]};
2.非规格数的舍入
wire [24:0] frac_round = {1'b0,frac0[26:3]} + {24'b0,frac_plus_1};
wire [7:0] exponent = frac_round[24]? exp0 + 8'h1 : exp0;
在我看来，上述代码忽略了00.111...1 + frac_plus_1情况下exponent的变化,
gpt说不考虑非规格数舍入对阶数的影响，这显然是难以令人信服的。