Machine Leaning In Actiong Commands Notes# 
## numpy数据库
- 进入numpy数据库：` form numpy import *`

- 随机产生一个n*m的数组：` random.rand(n,m) `

- 将数组转化为矩阵：` randMat = mat(random.rand(n,m)) `

- 将randMat.I存储起来： ` invrandMat  = randMat.I ` 
	
	注意：` .I`表示对矩阵取逆

- 执行矩阵乘法：` randMat*invrandMat`

- 处理误差：` myEye = randMat*invrandMat` ` myEye = eye(4)`

	注意：eye(4):穿件4*4单位举证