Python learning commands notes #

## Python基础

### 数据类型和变量

- 转义字符：`\n`表示换行,`\t`表示制表符，`r''`表示`''`内部的字符串默认不转义。

- 布尔类型：

	- `and`运算:当所有都为`True`时，结果才是`True`
	
	- `or`运算：只有一个为`True`，结果就是`True`
	
	- `not`运算：把`True`变成`False`, `False`变成`True`

- 空值：在Python中用`None`表示

- 除法运算：

	- `/`除法计算的结果是浮点数
	 
	- `//`除法计算的结果是整数，即取整运算
	 
	- `%`取余运算

### 字符串和编码

- Python的字符串

	- `ord()`函数获取字符的整数表示
	 
	- `chr()`函数把编码转换为相对应的字符
 
	- Python对`bytes`类型的数据用带`b`前缀的单引号或双引号表示：`x = b'ABC'`
	
	- 以Unicode表示的`str`通过`encode()`方法可以编码为指定的`bytes`:`'abc'.encode('ascii')`;`'雨洁'.encode('utf-8')`
	
	- 把`bytes`变为`str`，用`decode()`函数：`b'abc'.decode('ascii')`；
	
		`b'\xe5\x90\xb4\xe9\x9b\xa8\xe6\xb4\x81'.decode('utf-8')`

	- `len()`函数可以计算`str`包含多少个字符

- 格式化:`%d`表示整数,`%f`表示浮点数,`%s`表示字符串,`%x`表示十六进制整数
		
		>>>'%2d-%02d' % (3,1)
		'3-01
		>>>'%.2f' % 3.1415926
		'3.14'
		用`%%`表示`%`

### 使用list和tuple

- **list**:是一种有序集合，可以随时添加和删除其中的元素
		
		eg:
		>>>classmates = ['Michael','yujie','tracy']
		
	- **len()**函数可以获取list元素的个数
	- **append()**函数：可以在list中追加元素到末尾:
		- `>>>classmates.append('Adam')`
	- **insert()函数**：可以在list中的任意位置添加元素:
		- `>>>classmates.insert(1,'jack')`
	- **pop(i)函数**：删除`list`指定位置的元素,若`i=0`，则表示删除`list`末尾的元素：
		-  `classmates.pop(i)`
	- 把`list`中的某个元素替换成别的元素：
		- `classmates[1] = 'Sarah'`
	- 在`list`中也可以插入另一个`list`:
		- `s = [1, [8, 9, 10], 3]`
		- 则`9`则表示为:`s[0][1]`

- **tuple**:另一种有序列表：元组，但初始化后就不能修改
		
		>>>classmates = ('Michael','yujie','Tracy')

### 条件判断
	
- 如果：

		if<条件判断1>：
			<执行1>
		elif<条件判断2>：
			<执行2>
		elif<条件判断3>：
			<执行3>
		else:
			<执行4>
- 强制转换：

		s = str()
		i = int(s)         #将str类型转换为整型

### 循环

- `for ... in`循环：
		
		eg:
		names = ['Machael', 'yujie', 'Tracy']
		for name in name:
			print(name)           #打印names[]
	- `range(n)`函数:生成一个*0 - (n-1)*的有序序列

- `while`循环


### 使用dict和set

- `dict`:Python的内置字典,使用键-值(**key-value**)存储，具有极快的查找速度。

		eg:
		>>>d = {'Michael': 22, 'yujie': 17, 'Tracy':23}
		>>>d['yujie']
		17
		#一个key只能对应一个value

- `set`:与`dict`类似，也是一组**key**的集合，但不存储**value**.

		eg:要创建一个set，需要提供一个list作为输入集合：
		>>>s = set([1, 2, 3])
		>>>s
		>>>[1, 2, 3]
		#在set中，重复的元素将会被过滤:
		>>>s = set([1, 2, 2, 3, 3])
		>>>s
		>>>[1, 2, 3]
	
	- 通过`add(key)`和`remove(key)`可以添加元素到set中.
		
		- `s.add(key)` 或 `s.remove(key)`
	
- **sort()**：对list进行排序(str或int类型)
		
		>>>a = ['c', 'b', 'a']
		>>>a.sort()
		>>>a
		['a', 'b', 'c']

- **replace()**:替换函数

		>>>a = 'abc'
		>>>a.replace('a', 'A')
		'Abc'
		#但a的内容没有变，还是'abc'

## 函数

### 调用函数

- abs()函数：取绝对值

### 定义函数

- isinstance()函数：数据类型检查
		
		eg:isinstance(x, (int, float)) #检查x是否为整数或是浮点数
- return():return返回的值默认是tuple值

### 函数的参数

- **默认参数必须指向不变对象**

- 可变参数：在list或tuple前面添加一个`*`/,就把list和tuple变成了一个可变参数

- 关键字参数★
		
		def person(name, age, **kw)
			print('name:', name, 'age:', age, 'other:', kw)
		
		>>>person('Michael', 30)
		name: Michael age: 30 other: {}

		>>>extra = {'city':'Chendu', 'job':'Disigner'}
		>>>person('Yujer', 17, **extra)
		name: Yuje age: 17 other: {'city': 'Chendu', 'job': 'Disigner'}

- 命名关键字参数★

	- 如果要限制关键字参数的名字，可以使用命名关键字参数，例如，只接受`city`和`job`作为关键字参数。定义方式如下：
			
		 	def person(name, age, *, city, job)
		**`*`**后面的参数被视为关键字参数，调用如下：
					
			>>>person('Jakc', 24, city='Beijing', job='Engineer')
			Jack 24 Beijing Engineer
### 递归函数
	
- hanio塔

## 高级特性

### 切片(Slice)
	
- 取list或tuple中的部分元素

		>>>L = list(range(100))
		>>>L[0:2]
		[0, 1]
		>>>[0:-1]
		[0, 1, 2, ..., 99]
		>>>L[:10] #取前十个数
		>>>L[-10:] #区后十个数
		>>>L[::5] #所有数，每5个取一个
		>>>L[:] #取整个list
	- 同样，以上操作也适用于tuple
	- 字符串`'xxx'`也是一种list,也是用于上面的操作

### 迭代：通过for遍历list或tuple的这个过程，称为迭代（lteration）

- 迭代dict:
		
		>>>d= {'a': 1, 'b': 2, 'c': 3}
		>>>for key in d :
		...		print(key)
		...
		a
		b
		c

	- 默认情况下，dict迭代的是key.如果要迭代value,用`for value in d.values()`，如果要同时迭代key和value，可以用`for k, v in d.items()`。

- 判定一个对象是否是可迭代对象，通过collections模块的Iterable类型判断：
		
		>>>form collection import Iterable
		>>>isinstance('abc', Iterable) #str是否可以迭代
		True
		>>> isinstance([1,2,3], Iterable) # list是否可迭代
		True
		>>> isinstance(123, Iterable) # 整数是否可迭代
		False 

### 列表生成式★

- 要生成`[1x1, 2x2, 3x3, ..., 10x10]`
		
		>>>[x * x for x in range(1,11)]
		[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]


- for循环后面可以加上if判断，可以筛选出仅仅偶数的平方：

		>>> [x * x for x in range(1, 11) if x % 2 == 0]
		[4, 16, 36, 64, 100]

- 使用两层循环，可以生成全排列：

		>>> [m + n for m in 'ABC' for n in 'XYZ']
		['AX', 'AY', 'AZ', 'BX', 'BY', 'BZ', 'CX', 'CY', 'CZ']

- 列出当前目录下的所有文件和目录名
		
		>>> import os # 导入os模块，模块的概念后面讲到
		>>> [d for d in os.listdir('.')] # os.listdir可以列出文件和目录
		['DLLs', 'Doc', 'include', 'Lib', 'libs', 'LICENSE.txt', 'NEWS.txt', 'numpy-wininst.log', 'python.exe', 'pythonw.exe', 'README.txt', 'Removenumpy.exe', 'Scripts', 'tcl', 'Tools', 'w9xpopen.exe']
		