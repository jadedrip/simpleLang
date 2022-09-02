SimpleLang 语言

A compiler for SimpleLang which is a modern language.

Compiler = Flex + Bison + llvm

目标 & 简介
==============

SimpleLang 是拍脑袋的产物，试验性的产品，现在仅仅处于最初级阶段。随时会变化。
糅合了 go, Java, C++, Lua 等语言中我觉得“爽”的部分，作为个人兴趣爱好实现，不必太过期待。

它应该有以下特点：
*  它应该可以和 c 较好的融合
	也就是方便的调用 c 语言编译出来的库，并且用它编译的库，也可以被 c 语言较好的调用。
	*在后端采用 LLVM 的情况下，这个目标似乎不难实现。站在巨人的肩上，也可能让它更好的发展。*

*  它应该可以和 c++ 较好的融合
*  语法上会比较接近 Java，抛弃所有 C/C++ 中的复杂部分，但引入一些高级特性。
*  编译型语言，编译的代码应该有较高的效率。所有的类型都是“可决”（在编译期完全确定）的。
*  简洁&优雅，表现力强，行尾不加 ; 
*  原生的支持委托（或者说函数对象？）和闭包
*  原生的支持协程，多线程
*  原生支持 utf-8, unicode
*  支持国际化
*  可选的 GC
*  谨慎的支持操作符重载
*  使用一个简化的异常系统来处理错误。
*  支持模板

设计思想：

* 尽量避免对象的复制，凡是复制，都需要明确使用 clone


基础语法
=============
## 工程目录

SimpleLang 工程有固定的目录结构

```
[root]
	└ [doc]				文档目录
	└ [main]
		└ [resources]	资源文件目录
		└ [src]			源码目录，通过目录结构来定义包
			└ main.sc 	主入口文件（编译为可执行文件时有这个文件）
	└ [test]
		└ [src]			测试源码目录，
		└ [resources]	测试用的资源目录
	└ [subject]			子工程目录，除了没有 main.sc，其他和主工程一样，也可以在内部通过链接文件连接到其他目录
			└ 
	└ config.yml		配置文件
```



包
------------

文件头部不需要写包名，通过目录结构来确定类的包名

SimpleLang 程序的目录结构是固定的，入口文件被必须为 main.sc，而一个程序可以引入多个包（或者叫模块），包一般被 7z 压缩为 spk 文件，包的目录同样是固定的。

 

命名
------------

*	变量使用小写开头，可包含字母和数字，驼峰格式，禁止使用符号和下划线
*	类使用大写开头（内部类型除外），驼峰格式，禁止使用符号和下划线
*   函数/方面名使用小写开头，驼峰格式，禁止使用符号和下划线

变量类型
------------
支持的内置类型：

| 名称    | 符号 | 位宽   |
| :------ | :--- | :----- |
| boolean | 无   | 1 bit  |
| byte    | 无   | 8 bit  |
| char    | 无   | 16 bit |
| short   | 有   | 16 bit |
| int     | 有   | 32 bit |
| uint    | 无   | 32 bit |
| long    | 有   | 64 bit |
| ulong   | 无   | 64 bit |
| float   | 有   | 32 bit |
| double  | 有   | 64 bit |

注：内部类型在函数中使用传值方式传递，其他类型传引用

其他类型：

| 类型      | 说明               |
| --------- | ------------------ |
| class     |                    |
| interface |                    |
| singleton | 单例               |

语言级别支持的内部类

| 类型     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| Tuple    | 元组                                                         |
| String   | 字符串                                                       |
| Array<?> | 数组模板类，可以和数组无缝切换，特别的 Array<byte> 可以用原生字符串初始化。 |
| Any      | 可变类型                                                     |
| Func     | 函数对象                                                     |
| Delay    | 延迟对象                                                     |
| Optional | 可选对象                                                     |
| Delegate | 委托（保留）                                                 |
| Proxy    | 代理（保留）                                                 |

使用 const 来定义常量：

	const pi=3.1415	// 注意：常量如果可以推断，可以不需要类型定义

以及枚举：

	enum MyEnum{ red=0, blue=2 }	// 枚举和 int 可以无缝转换

枚举使用时为：

	MyEnum.red

变量
------------
SimpleLang 语言中除了内置类型（整数和浮点），其他类型都保存在指针中。   
**变量必须以小写字母开头，并且只能使用字母和数字，不能使用下划线。**

*设计语：通过将变量和类型使用大小写区分开，可以增强语法分析，避免歧义，禁用下划线是因为编译器会生成带下划线的函数，可以避免冲突。同时这也从语法层面，直接规范了风格，提高可读性。*

定义变量可以用 var 来自动推导，用右值推断类型，甚至允许先定义，使用时再推导。

	var i=10
	var x = y = 100		
	var a
	if(..){
		a = 30.0f
	}

不过变量的类型是确定不变的。因此以下代码是错误的

	var name = "Hei"		// 这里 name 自动成为 String 类型
	name = 15			    // 而这里会出错，因为 name 不能改变类型

另外，内部变量有初始值。

空指针
-------------------

变量必须明确使用 ? 符号来指示自己允许为空

	String? k 		// 默认初始化为 0
	assert (k is null)
	k = "10""
	k = null
	k = "20"


| 操作符可以在指针值为空时提供默认值

​	`var val = getValue() | defaultValue`

可为空的变量实际上是  Optional<T> 类型，下面两种写法相同

```
Optional<int> v = null
int? v = null
```

数组
------------
数值类型（不是变量）可以定义成普通数组，数组有**固定长度**，并且不能更改长度，有个默认打开的编译选项，会让越界访问抛出异常。数组实际上为 Array<T> 类型，（类型+[]） 只是简写，两者等价。
数组下标从0开始

    int[] a=[ 0, 1 ]			// 数组可以直接初始化
    Array<int> a = [ 0, 1 ]
    int[10] array2				// 初始化一个空的数组  
    int v=array2[1]     		// 数组取值
    
    // 通过内置的 size 成员函数来获取数组的长度
    var len = a.size()			// 注意，这个是编译期方法

当数组作为函数参数时：

    func myFunc( int[] array ){ ... }

也可以定义多维数组

```
int[2, 2, 2] vec = [ [ [1,2], [1,2] ], [ [1,2], [1,2] ]  ] 
int v = vec[0, 1, 1]
```

另外单维数组也支持切片

    int[] s=arr[startIndex:length]

需要注意的是，切片是引用，因此如果源改变了，切片同样会改。

注：如果想使用可变数组，可以使用 Vector 模板类。

## 对象数组

对象也可以定义为数组，但它有特殊性。

构造数组时，整个数组仅仅初始化内存空间，而不会构造内部的对象，并且空间是紧凑创建的，不会有对象头，内存会被置0，但不会调用构造函数。因此，你无法直接判定数组中的对象是否存在，是否已经被初始化。

而将对象放入数组，是一个**复制**操作，原对象和数组中的对象会脱钩，新对象的生存期完全跟随数组（除非手动从数组中删除），而从数组中取值，同样是一个**复制**概念的操作。当然，编译器会尝试分析生存期进行优化，如果变量没有逃逸，是不会有真正的复制操作的。

```
MyCls[2] myClss
var zero=myClss[0].val		// 对象还未构造，但 zero 的值是0，因为内存被置0了
if(myClss[0]) doSome		// 不能这么判断，表达式永远为真，编译会报错误
if(myClss[0].exists) doSome	 // 可以在 MyCls 里定义一个 boolean exists=true, 由于数组默认置空的，就可以用来判断对象是否存在了
myClss[0] = MyCls()		// 可以认为是 myClass[0] = clone(MyCls()), 当然，编译器会进行优化
var v=myClss[0]			// 原则上等于 v=clone(myClass[0])
v.val = 11			    // 数组内的对象不受影响
const x=myClss[0]		// 这样不会进行复制，x 被认为是 myClass[0] 的别名
x.val = 11				// 数组内的对象被改变
```

这么设计的目的，是极大的降低对象数组的开销，并把数组交给程序员完全管理，对象数组实际可以被看成一个内存池。对象数组很容易出错，因此使用需要谨慎，如果不追求性能，用容器类吧。

内部类 Any
-----------
Any类型可以保存任何值，并且保存类型信息。

Any 类型允许在**运行期**保存任何对象，可以判断它内部是什么类型。

	Any i=20.0f    // 保存一个 float

然后你可以这样用

	assert( i is Any )
	
	when(i){   // 用 when 关键字进行运行期类型判断
		int : print(i)	// 在这个分支，i 被自动转换为 int 类型
		
		float : {
			// do float
		}
		default : {
			printf("unknown Type")
		}
	}
	
	if( i is int ){	// if 中如果有类型判断，块中会自动转换为相应的类型
		int b=i+1
		... 
	}
	
	Type type=i.type	// 获取类型（参见**反射**）
	float x=i			// 或者 (float)i 强制获取 float 类型的值

但是，如果取值时，类型不一致，并且不能进行隐含转换，将抛出一个异常，这个过程是**运行期**的。

分支
------------
if 采用 c 的语法, 增强 switch。

switch 语法如下，支持多种数据以及多种比较，只要是测试相等就可以。冒号后如果是多行，需要大括号。
并且不需要 case。

	switch vegetable {
		"celery": vegetableComment = "Add some raisins and make ants on a log."
		"cucumber", "watercress": {
			vegetableComment = "That would make a good tea sandwich."
			comm = "多行需要大括号"
		}
		default: vegetableComment = "Everything tastes good in soup."
	}

对数字也可以使用范围

	switch intValue {
		1..10:		v="1 to 10"
		20..30:		v="20 to 30"
	}

元组
--------------

SimpleLang 语言中支持元组，类似 C++ 中的 pair, tuple。Si 里的元组用圆括号括起来，必须从明确的值创建，并且创建后 **不可修改**
元组必须在创建时赋值，并且值不可更改。可以通过 := 来解构，或者使用[]取值，元组可以参与编译期运算。

	var a=(1, "second", x)				// 直接创建
	print( a[0] )						// 取第一个值（注：[] 操作是编译期的）
	if( a[1] is int ) print("yes")		// 通过索引取类型
	
	for( var i : a ){					// 通过 for 循环，在编译期解开元组
		print( i )
	}
	
	var n= (10, "Hello") :+ (20, "你好")  // + 可以拼接元组，结果为 (10, "Hello", 20, "你好")
	var t=1 :+ (10, 20)					// + 也可以把元素加入元组成为一个新元组，这里等价于 var t = (1, 10, 20) 
	PS: var x = you( myFun() :+ 10 )		 // 考虑到函数返回直接用 + 容易引起二意，还是用 :+，冒号代表操作元组
	
	var b0, b1 := a				// 元组的自动解构，注意复制的是引用，变量数量可以比实际的少，但不能多。
	int c0, float c1 := (10, 10.0)
	
	var c=(0)			// 这不是元组，c是 int 类型


​	

另外，元组的成员也可以命名：

	var tuple=( key=1, value=2 )
	print( tuple.key )

特别的，元组必须放在 = 右边或者接 -> 操作 ，也就是无根的元组是违法的。

	( 10, 20 )		// 编译错误

循环
--------------
支持 while, for 循环，c 的语法。但不支持逗号多定义，多步进，不支持 do-while。
另外支持 for-each 形式

	int[] arrays = [10, 20]
	for( var i : arrays ){
		i = 30		// i是引用，这里将改变 arrays 中的内容
	}
	
	for( int i : 1..20 ){
		...
	}

作为一个语法糖，在循环内使用 free 语句释放迭代器，编译器会尝试调用容器的 remove 方法（如果有），将对象从容器中移除。
remove 的返回值赋值给 i, 重新开始循环体 (continue)

	for( var i : list ){
		free i		// 等价于 i=list.remove(i) continue
	}

特别的，如果列表里保存的是元组（比如 map )，可以使用自动解构的语法

	for( var k,v : map ){	// 同样，注意复制的是引用，因此改变 v 会改变 map 内的值
		free k
	}

字符串
--------------
在 SimpleLang 里的字符串类是个内部类型，String，字符串类内部维护字符串编码。一般认为是 UCS-4 编码，表情符号占两个字符。 

	String eng="Hello world!"			
	String str="中文"					
	char aChar=str[0]					// a='中', 取出某个字符，为 UCS-4 编码
	String str( bytes, Charsets.utf8) )	// 通过 bytes 指定编码来创建
	str.bytes()				    		// 获取 byte，不指定编码，会默认返回 utf-8

另外，字符串也支持切片。

	String s=str[0:1]	// 注意，这里不会复制内部字符串

连续多个字符串会拼接为一个

	String s = "Hello " "World"

字符串通过操作符重载允许进行 + 操作，并且可以和整数、浮点数加，结果是字符串。

	String s="" + 16		// 结果是字符串 "16"
	s=R("Hello", "zhCN")	// 从资源文件获取字符串

双引号支持字符串模板，单引号不解析模板

	String s="Value=$val and key=${cls.key}"  // 字符串模板
	var x = 'No $Template'

**注意：字符串内容不能更改。**
如果需要可变字符串，使用另一个兼容类 StringBuffer。

操作符
-------------
支持大部分 C++ 操作符，但是**不支持前置 --, ++**。
支持 >>> 运算符（无符号右移）

函数定义
-------------

函数（方法）名必须使用使用小写字母开头，并且**不能使用下划线**。 
函数这样定义

	func first( int a ) : int {
		return a
	}

调用时：

	var x = first( 10 )

并且为了保证定义的清晰，如果省略返回值的定义，就是表示不返回。
参数允许可变参数,不过必须定义在函数的最后，也只允许一个可变参数.

另外允许多返回值，这时返回值会被包装为一个元组。
多返回值函数定义方式如下，返回值可以匿名也可以命名，命名的返回值在函数内可以直接作为变量操作.

	func second( int a, var b, int ... args ) : int retval, int val {
		// 这里 args 被视为数组 array
		if( args.size > 0 )
			val = args[0]
		retval = a + b		// 直接操作返回值
		return	   // 可以省略变量列表
		int x = 12 // 编译错误，return 必须在块的最后 
	}

注意，返回值如果命名，那么在函数开始，就会调用无参数构造函数构造返回值，如果没有无参数构造函数，编译会失败。

单行函数（语法糖）

	func add(int a, int b) = a + b

单行函数使用推导获取返回值，必定有返回值，因此也不需要 return。



return
----------
* return 语句必须写在区块的最后，本区块后面不能有其他语句
* 如果函数返回值都是命名的，那么可以不带后面的返回参数，特别的，没填充的变量会以默认值返回
* 如果 return 后面带了返回参数，那么必须写全
* 函数最后的 return 允许省略

可变参数可以是同一个类型的，或者使用 var 让它成为可变模板函数

	func varFunc( int a, var ... args ){
		for( var i : args ){    // 这个 For 会在编译期被展开
			run(i)
		}
	}

上面这个 for 循环会在编译时被展开成顺序的多个代码块。

	func varFunc2( int a, Any ... args ){
		//  args 被视为 Any 数组
		for( var i : args ){    // 这个 For 会在运行期被展开
			run(i)
		}
	}

函数可以使用返回元组的形式来返回多个变量，并且你可以用自动解构。

	var first, second := fun( 10, 20 )

返回值如果有非命名参数，那么**必须**写在列表的前面

	func second( int a, var b ) : int, float, int {
		return 0, 15.0, 2	
	}

传参
================
SimpleLang 语言中，传入的参数如果是值类型（int 等数字），会被复制，而对象被视为引用，因此**它的内容**可以在函数中可以被更改。

比如：

	String old="Hello"
	cut2(old)
	print(old)	// 输出 "Hell"
	
	func third( int a ) : int {
		return a+1
	}

参数中可以使用 var 关键字，这时候它同样被视为模板函数。
返回值也可以使用 var，这时通过 return 来推断返回值

	func myFunc( var a, int b ) : var ret {
	   return a+b   // 这时推断返回值为 int 类型
	}
	
	int x=myFunc( 10, 20 )

特别的，如果参数上加上了 clone 关键字，那么这个对象会被复制进入函数

```
func myFunc( clone int clonedValue ) {
	clonedValue.x = xxx	// 不影响原始变量
}
```



函数调用
-----

函数使用比较宽松的调用形式，可以是顺序的，比如：

	var first, second := fun( 10, 20 )

或者命名的形式：

	var v = fun( name="myname", value=20 )

也可以2者组合

	fun( 10, 20, name="myname" )

但是有个约束，包括，顺序形式的必须在函数调用的开头。并且所有的参数（除非有默认参数）都必须充满。

下面的写法是非法的（除非第一个参数就是 name）：

	var v= fun( name="myname", 10, 20 )

函数对象、匿名函数
-------

SimpleLang 在语言级别支持函数对象、匿名函数，匿名函数**不能**是模板的，参数不能有默认值，不允许可变参数。

	var add=func(int a, int b) : int{ return a+b }	// 匿名函数
	int a=add(10, 20)								// 执行

如果没返回值，没有参数，都可以省略

	var my1=func(int a){ ... }			// 无返回值
	var my4={ return 20 }				// 语法糖: 无参数时 = 后面 func 可以省略， 返回值类型自动推导
	func(int):float itIsAFunctor		// 明确的类型

同时，匿名函数可以引用外部变量（作为引用）：

	int myVal = 10
	var x=func(int a){ return a+myVal }		// 注意这个 myVal 是引用，在匿名函数调用时取*当前*值
	
	assert( x(20)==30 )

上面的代码演示了简单闭包，不过要注意的是，并行的情况下，myVal 可能被更改、互斥，这时候使用闭包需要特别小心。
另外，匿名函数里包含的是对象引用，因此如果在匿名函数里修改 myVal 的值，当匿名函数被调用时，myVal 就会被更改。
这点需要注意。

异常
-------
SimpleLang 支持的异常。

	/// 语言内部异常，所有异常的基类
	class Exception{
		String message	// 异常信息字符串
	}
	
	// 定义一个异常
	class IOException : Exception		// 定义一个新异常
	class HttpException : IOException{		
		int code
	}
	
	try{
		var a=func( 10 )
	}catch( HttpException IOException e ){	// catch 允许多个异常类型
		print( e.message )
	}finally{
		// 最后会执行的代码
	}
	
	// 简化的异常处理格式，对函数的异常直接处理，需要注意的是，函数后面的 catch 只能有一个
	var i=func( 10 ) catch(e) {
		print(it)  // it 是 Exception 类型
	}
	
	func(10) catch {}	//明确忽略异常

如果一个异常未被捕获，会转去 **公共异常处理函数**，对于线程/协程 将打印日志，然后结束线程/协程, 如果主线程被关闭，那么程序将退出。

一个函数也可以使用 nothrow 关键字明确声明自身不抛出异常

	func nothrow willNotThrow() : int 

注：一个 nothrow 的函数，编译器会**尽量**检查异常情况，如果调用了带异常函数而没捕获，将出现编译错误。
而如果 nothrow 的函数内抛出了空指针之类的未知异常，将无法捕获，而直接转去 **公共异常处理函数**。类

基础
----------------
每个文件（.sc）可以定义一个或多个类。
访问控制被简化，si 中的类类似 Java。成员变量、方法只有**公开**和**包内**的，公开的可以被包外访问，
否则只允许同名包或者*子包* 或者继承的类来访问。

*包 org.first.second 是 org.first 的子包*

## 纯数据类

单纯保存数据用，类似 c 里的 struct。不具有成员函数（也没有的 get/set）。纯数据类构造函数默认生成，而不能自定义，构造函数按顺序填写字段，并且默认空值。

```
data MyData{
	int val;
	String str;
	
	// 默认生成
	init(int val=0, string str=null);
}

MyData x(10, "你好")
```

纯数据类可以继承，并被一般类继承，但不能从一般类继承。

## 一般类

代码开始

	/* File MyCls.sc 开始 *
	class MyCls {	// 定义类
		// 语法糖在变量前加个点，会自动赋值到内部变量
		init(int .privateValue = 20 ){}	// 变量前加 . 等同 this.privateValue = privateValue
	
		finalize{           // 析构函数始终是无参数的，不需要括号
		}
	
		clone{              // 克隆函数
			return MyCls(){
				it.key = clone(this.key)
				it.value = clone(this.value)
			}
		}
	
		int key = 1			// 创建时初始化（先于构造函数）
		int value			// 创建时默认为0
		
		func do_something(){
			this.key++  // this 是自己
		}
	protected:	// 类中有且仅能有一个 protected 分割线，分割线上部的是公开的变量、方法，下部是
				// 保护的，只有在同一个类、子类或继承类内可以访问
		int privateValue	// 内置类型初始化为 0
	}

注：成员变量的默认值必须能确定，不能是模板的，也不能是成员函数调用或引用另一个成员变量（这时类还没构造）

类里没有静态变量或方法，请用函数、全局变量来替代。

*设计语：使用 Type name 这样的方式构造，可以帮助 IDE 自动补全（输入 My, IDE可以帮你连变量名一起补全了)*

继承&重载
-------------------

继承和重载的概念被简化，类可以单一继承，可以有多个接口实现。但类不再有虚函数，改用函数对象替代。

	class Base{
		func cantOverload(){	// 普通函数不可以重载
	
		}
		
		func(int) virtualFunction = null 	// 代替纯虚函数
		func(int) canOverload = func(int v) {
			doSomethine()
		}
	
		var myFunc = func(int v){		// 函数对象
			print(v)
			virtualFunction(v)	// 调用虚函数
		}
		
		const func(int) constVirtualFunction = null 	// 真纯虚函数
	}
	
	// 类可以继承，只能单继承，但可以有多个接口
	class Second : Base, Interface0, Interface1 {        
		func cantOverload(){	  // 这会是个全新函数，编译器报警
	
		}
	
		virtualFunction = func(int v){	// 重载虚函数
			print(v)
		}
	
		myFunc = func(int v){
			Base:canOverload(v)		// 强制调用基类函数
		}
		
		constVirtualFunction = func(int v) {
		
		}
	}
	
	Interface0 obj = Second()
	obj.virtualFunction = xxx // 还能改
	obj.constVirtualFunction = xxx // 编译错误，不能更改

相应的，类没有虚类或者纯虚类，所有类都可以被构造，如果有些类的函数没实现，就是一个空的函数指针，可以通过后期赋值的方式来实现。如果要防止它被构造，可以把构造函数放入  protected 区域。“虚函数”前可以添加 const 关键字，有 const 关键字的变量构造后就不能再更改了，因此编译器对这种变量可以优化实现。

## Get & Set

SimpleLang 支持成员变量的 Get & Set，set 方法在变量设置时被调用，而不会预先设置值。

```
class MyCls {
	int valueA;
    
    get valueA {	
        return valueA
    } 
    set valueA(int newValue){  
	    valueA = newValue
    }
    
    get fakeValue: int {		// 可以 let x = myCls.fakeValue 这样调用
    	return valueA + 10
    }
	
	get virtualValue = func(): int {	// 可以 let x = myCls.virtualValue 这样使用
									 //   另外可以 get(myCls.virtualValue) = func() -> int {}	这样“重载”
	}
	
	set virtualValue = func(int newValue) {
	
	}
}

class YouCls : MyCls {
	get(virtualValue) = ...	// 继承内重写
	int b
}

YouCls you
print(you.valueA)	// 返回 b值

MyCls cls
get(cls.virtualValue)=func(): int{ // 外部重写 set 方法

}


```



类的构造
-----------------

对象构造使用构造函数的形式，括号不可省略。

    MyCls my              	// 括号可省略
    var a=MyCls(10, 20)		// 通过构造函数构造，参数表使用逗号分割，当然可以 var 推断
    List<String> arr= （"Hello", "World"）	// 通过元组初始化列表
    
    MyCls c(10){     		// 小技巧，在构造时，后面直接接大括号，在构造后，直接执行语句块
    	key=0				// 在构造函数执行后执行
    	val=20
    }

对象不构造时，必须赋null值：

	MyCls a = null

对象的传递，都是浅copy，除非明确指明复制

	MyCls a=clone(b)	// clone 会调用复制函数进行深 copy。

对象可以被理解为都保存在智能指针中, 指针的赋值需要使用等号。

	MyCls x=null
	if( x==null ){			// 可空对象和 null 的比较，会判断对象是否为空
		x=Cs()          	// 这里会改变 x 指向的对象
	}
	
	Cs a
	Cs b = a    // b 指向 a
	b.val = 1   // 这里同时会改变 a 指向的对象值

另一个指针专用操作符是 ?:，在指针为空时返回对象（语法糖）

	int a = nullable() ?: defaultValue		// 为空时 a 赋值为默认值

*设计语:操作符重载有可能引起歧义，需要谨慎思考*

类外部方法增强
----------------
通过在类外部定义额外方法，可以增强类

	fun MyCls.other(){	// 本函数定义在外部，通过 import org.other 引入
		this.val++
	}
	
	MyCls cls()
	cls.other()			// 可以像内部方法一样使用

循环解偶
-----------------
两个类互相引用对方的情况是被禁止的（即使是间接引用）。但可以定义子类。
子类只允许在类内被构造，并且可以访问父类的变量。

*设计语：循环引用本身是一种并不太合理的设计，干脆从语法上禁止了*

	class MyCls3{
		int var=0
		class SubCls{
			int subVar=2
	
			func incVar(){
				var+=subVar // 子类可以访问父类的成员变量
				super.print()  // super 是父类的指针
			}
		}
	
		SubCls cls=SubCls()
	
		func print(){
			Console.print(cls.subVar)
		}
	}

垃圾收集
------------------

对象分托管和非托管两种，托管的对象会由 GC 管理，而非托管对象必须手动释放。但不管托管或者非托管对象，都可以有析构函数，
托管对象的析构函数仅手工调用或触发 GC 时才会被调用。

对象默认是托管的，非托管对象一般人不推荐使用。

	var managed = ManagedClass() 	// 托管的
	free(managed)					// 调用析构函数
	
	var unsafe = new Unsafe()
	free(unsafe)			// 析构

语法糖：对象作用区
----------------

通过在对象后直接挂接代码块，可以以这个对象为“基准”来执行代码。区块中的所有函数、变量会先在这个
对象内部查找。	另外，代码块中默认使用 it 代表本对象。  
**注意，代码块仅仅在对象不为 null 的时候才被执行**

	var i = a {		// if(a!=null) 才执行
		doSomething()
		it.name = "hello"	  // it 关键字代替本身
	}

这相当于：

	if(a != null)){
		a.doSomething()
		a.name = "hello"
	}
	var i=a

*设计语：块还是限定为禁止返回，否则最后一个空荡荡的变量容易引起混淆*

某些时候，为了防止多重嵌套代码块中 it 冲突，你可以通过 it 重命名来给 it 指针命名：

	class MyCla{
		fun my(){
			a { other :
				other.hello()	
			}
		}
	}

显式类型转换
--------------------
除了默认类型转换，还可以使用下面的显式转换，如果后面接操作符，显式转换优先进行.

	var a=(MyClass)b			// 尝试将 b 转换为 MyClass 类型
	(MyClass)b.funcInMyClass()	// 先转换在调用
	(MyClass)b{					// 转换再调用对象作用区
		funcInMyclass()
	}

但显式转换也是有限制的，比如你并不能把 int 转为一个不兼容对象。显式类型转换仅能用于基类转换，等同 c++ 的 dynamic_cast

单例
---------------------

单例受到语言级别的支持。它的声明类似 class, 仅仅是把关键字 class 改为 singleton。

	////// 文件开始 ////////
	singleton MySingleton{	// 单例的公开定义部分
		func astCallit(){}
	}

当编译器发现包被引用，就会在程序启动时**线程安全**的初始化所有包内的单例，并且到程序关闭时才被析构。

	import org.MySingleton	// 引用就初始化

模板
==================
**注意：凡是涉及模板的类、函数，都必须通过源码的形式存在导出包里。**

## 模板类

可以通过把类中的成员函数，定义为 var 来创建模板类，模板类必须在构造时，能确定所有模板成员的类型。

	class MyTuple {
		var left
		var right
		init( var .left, var .right ){}		
	}
	
	MyTuple<int, int> v = MyTuple(10,20)	// 通过构造函数确定所有类型

或者和 Java 类似，用命名的类型占位符来定义模板类

	class MyMap<KEY, VAL>{	// 注意：类型占位符的约束是必须全大写
		KEY key
		VAL val
	
		init(String name){	// 
	  	}
	
		func templateFunc( var a ){		// 函数直接使用 var 来定义模板函数
			if( a is int ){		        // 这里的 is 是编译期的操作符，因此这里的 if 也是编译期的
				a++
			}
	
			def A = b
			A b							// b 定义为 a 相同的类型
	
			Type c=typeof(a)			// Type 是种描述类型的特殊类型
			when( a ){					// 用 when 判断类型
				int : {
	
				}
				float : {
	
				}
				default : {
	
				}
			}
		}
	}
	
	var my = MyMap<String,int>("Hello")		// 构造时必须可以推导类中所有类型

## 模板函数/成员函数

当参数使用 var 或者使用类型占位符来定义时，这个 函数/成员函数 就是一个模板函数

```
func templateFunc( var a, int b ) {
	...
}
```

**对于模板函数，参数类型确定了以后，返回值类型也就被确定了。**

如果你希望返回值的类型在函数中来推导，那么需要使用 = 来连接函数定义和函数体 

```
func<T> templateFunc( T a, T b ) = {
	return a+b
}
```

## 内部函数 typeof

虽然 typeof 看起来像函数，但它其实是在编译时起作用，用来推导类型

类型定义 def
------------------

可以使用 def 来为复杂类型，取一个别名

	def AFun = func(int, int):int
	def MapClass = MyMap<int, String>		// 定义模板类
	
	var m = MyMap( 10, "Hi" )
	def IntMap = m						// 可以理解为 def IntMap = typeof(m) 的语法糖

需要注意的是，def 定义的类型是仅仅是原类型的别名。

常量推导
------------------
如果常量传入模板函数，那么函数在编译期，就会被计算并展开

	func myTemp( const a ) : var c{ // 通过 const 关键字保证只有常量可以传入
		if( a == 1 ){
			return a+10
		}else if(a=="Hello"){	// 传入 常量整数时，这分支都不会被编译
			return "World"
		}
	}
	
	myTemp( 10 )	// 在编译时不会生成函数，直接替换为 a+10
	
	var x = 10
	myTemp( x )		// 编译错误，禁止传入变量
	
	const y = "Hello"
	myTems( y )			// 传入的是常量，按模板编译

类型操作符
-------------------
SimpleLang 将支持一些类型操作符，结合模板，可以实现编译期编程。

操作符 is
------------

在编译期判断类型可以使用 is，语法是

	A is B

A 允许是变量或者模板变量
结果将是 1 或 0。A 可以是变量，或者模板参数，B 为类型或接口。需要注意的是，这里并非要求 A,B
是完全一致的类型，当 B 是从 A 继承，或A实现了接口B，也将返回 1。
但相对的，如果 A 和 B 都是模板类型，那么模板参数不一致（即使他们有继承关系），那也返回 0

操作符 ===
-------------
在编译期判断类型是否完全相等

	A === B

A 可以是变量或者模板变量，B 必须为类型或接口，和 is 相近，但 === 要求类型完全相等。

操作符 if
------------
当 if 后的括号内是一个类型，那么它就成为一个编译期的类型操作符，仅当条件为 0 时，编译 else 语句块，
其他任何类型都编译 then 语句块。

	if(a is int){		// 当 a 类型为 int 时被编译
		int b = a+10	// 这里 a 会自动改为 int 类型，不需要强制转换代码
	}else{
		a = "Hello"	// 虽然类型错误，但这里没编译，因此不会报错
	}

操作符 `（反引号）
-----------------
反引号将尝试从类型中按名称取出成员，如果成员不存在返回 0，存在返回成员的类型。 这可以在编译期判断类是否包含某个成员。

	 if( a`name` ) ...
	 if( a`myfunc` is func(int, String):String ) ...

操作符 for
-----------------
for 可以用来解开通过 ... 传入的多个参数等，也可以解开元组，这个过程是编译期的。

	func my( var ... attrs ){
		for( var i: attrs ){
			// 这里 i 的类型会按输入变化
		}
	
		var x=( 10, 20, "Hello")
		for( var i: x ){
			print i
		}
	}

操作符 ==,!=,||,&&
----------------
当两个常量进行布尔运算，他们也会在编译期运算为 1 或 0。

	var a=(1==1)		// 1

## 模板推导函数

由于函数的返回值可以通过 return 来推导，因此可以通过写一个完全静态的函数，来实现计算类型的模板函数。

```
func TplFunc( var a, var b ) = {
	if( a is int && b is int)
		return 1		// 真类型，if( TRUE ) 永远真，并且在编译期就处理
	else
		return 0
}

var a = 10, b=10
if( TplFunc(a,b) ){	// 静态语句，在编译期展开
	int c = 10
}
```

# 接口

SimpleLang 可以通过 interface 关键字定义接口，是一个抽象类型，是抽象方法的集合，接口所有的方法、变量都是公开的。

接口必须以源码的形式导出。

接口可以带默认方法、变量默认值，但需要注意的是，接口的方法会被认为是函数对象，接口内如果包含模板变量、方法，它只能被用在使用源码导出的函数里，事实上，如果函数体是使用源码导出的，编译器会按模板函数的方式来编译带接口的函数。

比如

	interface MyInterface{
		int value
		func getSome():int	// 这是个函数定义
	}
	func notTemplateFunc( MyInterface inc ) // 函数体通过二进制（c函数）方式导出 	

有且只有几个简单条件的接口，可以通过尖括号在参数中直接定义（匿名模板接口）

	void aFunc( <int a, String b> inc ){ // 传入对象必须有个int型成员变量a, 一个 String型变量b
		inc.a++
	}

接口无法被实例化，但是可以被实现。实现接口的类会生成接口定义的成员变量和函数指针。

	class MyClass : Base, MyInterface{	   
	}
	
	MyInterface i=MyClass()		// i 被认为是 MyClass 的基类
	
	void bFunc(MyInterface v){  // 必须从 MyInterface 继承的对象，才能传入
	                            
	}

或者，接口也可以隐式实现：

	class MyClass {
		int value;
		func getSome(): int {
		
		}
	}	
	// 虽然 MyClass 并没有显式实现 MyInterface，但它包含了 MyInterface 所需要的所有元素，因此也可以直接传递给接受 MyInterface 作为参数的函数。
	func myFunc( MyInterface a ){} 
	MyClass x
	myFunc(x)	

另外，和 Go 不同，纯空的接口是非法的。

# 语言特性

## Optional<T> 对象

Optional 可以保存一个内部对象，可以通过

    Optional<int> opt=12
    opt.isPresent()	// 是否存在
    
    opt->(int v){ // 当值存在时被调用
    
    }
    
    int? optInt	// 其实是  Optional<int> 的简化写法



线程
--------------

创建线程由线程库支持，类似 Java

	Thread thread(daemon=true, level=3, loop=false) // loop = true 时线程函数会反复执行，直到线程收到中断信号
	thread->{       // 运行线程
		aFunc()
	}
	thread.cancel()		// 尝试发送信号关闭线程
	thread.join()	 	// 等待结束

如果需要锁，代码如下

	Mutex myMutex=Mutex()			// 定义一个锁
	myMutex -> {
		// 锁内
	}													// 这里解锁

原子操作由库来支持：

	var a=Atomic(10)	// 原子的 int
	int v=a++           // 原子的 +1 并返回新值
	int cur=a.compareAndSet( 11, newValue )

另外，如果库是二进制实现（无引用计数），那么可以在函数参数上添加 $ 符号，强制引用，
由库内来释放它(仅仅在库内处理有多线程等逃逸的情况下有必要），这样编译器在调用函数时，
不会额外增加一次引用计数。
当然，未来二进制包的函数定义是由编译器来生成的，因此一般情况下用不到。

	func myLibFunc( $MyObject obj ) // 这说明 obj 在函数内会逃逸


异步协程
---------------

同时，Si 包含一个小的语言库，支持协程，并且尽可能自动维护，这里的协程近似 Go 语言的协程，是异步执行的。
在一个函数、区块调用前加上 go 关键字，这次调用就会在一个新的协程中并发执行。
当被调用的函数返回时，这个协程也自动结束。

	go {	// 通过go来创建一个并行任务
		print( "go" )
		yield();  // 放弃 cpu
		sleep(x); // 放弃 cpu 并等待最少 x 毫秒后继续
	}
	
	go dosomthing()		// 并行执行函数

另外 go 的返回值是一个协程对象，可以有限度的操纵协程。

	func doSomthing() : int 
	
	Coroutine<int> c1=go doSomethine()
	Coroutine<int> c2=go doSomethine()
	....
	var v1= c1.await(4000)  // 等待协程执行完毕，最少 4000 毫秒后还未结束将抛异常
	var v2= c2.await()

SimpleLang 通过通道来支持跨协程数据交换，成员函数 await 可以把异步操作写得更像同步操作。

	var chan=Chan<int>()	// 实例化一个通道
	
	go {				 // 并行执行语句块
		int i = chan.await(4000) // 这里会阻塞，直到 4000毫秒后超时抛出 TimeoutException 异常，或者 chan 被其他线程调用，参数会作为 await 的返回值返回。
			catch(TimeoutException e){
	
			}		 
	
		// 后续的代码
		print(i)	// 输出 10
	}
	chan(10)	// 调用通道，把数据塞进去，这里会阻塞，一直到数据被取走
	
	var cachedChan=CachedChan<int>(10) // 带缓存的通道，缓存满前不会阻塞

特别的，如果一个协程被阻塞，它可能会被调度去干别的事，因此唤醒可能并非“及时”的。

包 & import
============
SimpleLang 通过 import 导入包，import 只能写在文件头部，简单起见，SimpleLang 总是一次导入包里首层所有的变量、类定义、函数等，而其他层不能在包外访问。

	import org.simplelang

如果包有冲突，那么可以创建包别名

	import org.simplelang as sl

sl:MyClass my

也可以用全名来使用包内函数或对象而不需要导入

	org.simplelang:printLine("Hello")

包只有根目录下函数、接口、类才能被其他模块访问。

```
org.simplelang.inner:StringImp imp	// 编译错误，无法访问
```

## 反射

SimpleLang 支持**静态**反射

```
func myTemplateFunc( var param ){
	for( var i,name of param ){	// 枚举 param 的成员变量、成员函数，它会被展开为代码，name 是它的名称，是个静态字符串，由编译器支持
		if("open"==name){	// 如果这个字段叫 open
		
		}
		if(name.startWith("my")){ // 
		
		}
		
		if(i is int){
		
		}else if(i is func){	// 如果是成员函数
		
		}else if(i is func(int, int)){
		
		}
	}
}
```

注意，由于是静态反射，因此模板函数里的代码必须是静态的，另外特别设计静态字符串，支持有限的几个方法。

# 其他

注解
------------------
SimpleLang 支持注解，未来在插件里支持注解的使用

	class MyClass{
		@ReflectName( name="value", idx=12 )	// 使用注解对象来进行注解
		int a 
	
		void doFun(){
		}
	}

C 对象定义
-------------

    @Clang("my_c_object")
    class MyCObject
    {
    	@Clang("my_obj_add" )
        func at( int idx ) : int  // int my_obj_add( my_c_object* me, int idx )
    
        func size() : int  // int my_c_object_size( my_c_object* me )
    }

和其他语言协作
---------------------
可以引入 c 或其他语言写的库会被编译成包，以便被 SimpleLang 调用。Si 语言可以输出标准 c 函数，以便被其他语言调用。
lib 文件、需要对应的头文件及适配文件等需要的东西，会被某个处理软件打成一个包，并放在编译程序能找到的地方。
而 SimpleLang 可以编译成 c lib, 函数会按**约定**转换成 c 的格式。

操作符重载
----------------
SimpleLang 支持有限的操作符重载，可以对类重载一元或二元操作符，但不支持二元操作符在前方的重载

	class MyClass{
		operator + ( int right ){	// 二元操作符的函数重载（默认的返回 MyClass 类型）
			return this
		}
	
		operator ++{					// 自增在后
			// return this 可省略
		}
	}

备选（思考中，暂时不实现）
==============

延迟优化( Delay 类型)
----

SimpleLang 的函数参数，允许使用延迟生成的技术以优化效率。它让参数仅在被首次使用的时候，才会被生成它。
比如：

	trans_data( get_data(), x)

而 trans_data 的代码如下：

	func trans_data( var v, bool x ){
		if(x) print(v)
	}

这段代码里，v 通过 get_data() 获取值，但在 trans_data 中，如果 x=false，v根本不会被使用。这个时候 get_data() 的调用
是完全没有必要的。而通过延迟生成技术，只有在v参数实际被使用时才会尝试“构造”它，因此，如果 x=false，get_data() 会被直接
放弃，生成的代码类似下面的

	void trans_data( bool x ){
		if(x) print( get_data() )
	}

要启用延迟优化，调用代码不用做任何更改，只要函数是接受 Delay<?> 类型的参数。

	trans_data( get_data(), x)		// trans_data 的第一个参数必须是 Delay<?> 类型
	
	func<T> trans_data( Delay<T> v, bool x ){
		if(x) print(v)
	}

其实也不一定用在函数里

	Delay<int> x={ get_data() }		// 这时 get_date() 其实没有被执行
	var k=x							// 这时才会执行，并且只会执行一次
	var k2=x						// 注意，这里不会重复执行


--------------

## 后置函数调用

函数另一种调用方法是通过 :: 后置

 ```
10 :: fun 	// 等价于 func(10)
 ```

元组也支持 :: 操作

	(10, 20) :: myFunc 	// 等价于 myFunc(10, 20)
	let tuple=(10, 20)
	tuple :: myFunc		// 等价于 myFunc(10,  20)
	let v = ((10, 20) :: firstFunc) :+ 30 :: second // 等价于 let v = second( firstFunc(10, 20), 30 )

如果你想玩一下函数式编程，这种语法也许会让你的程序更容易阅读

非托管对象
--------------

某些类可以用 class* 定义为非托管类，托管类在构造时不使用 GC 以提高性能，并且必须手工 free。

	class *UnmanagedClass{
	}
	
	var unmanaged=UnmanagedClass()
	free(unmanaged)

非托管类如果构造托管类，也将使用非托管的方式构造（注：这里可能有危险，谨慎使用）

对象追踪
-----

	class Connect
	
	class MyObject
	
	var conn = Connect()
	var my = MyObject() link conn
	var myRef = (my:conn)

my 对象的生存期将会跟随输入的对象 conn，成为 Connect 的子类。


编译器插件
----------------
在代码中可以嵌入由插件程序解析的代码，插件程序会把代码翻译为 SimpleLang 语言。

    var json = ```json```
      { im : " }
    ```

这段代码会调用一个叫json的插件，把中间的代码解析为 SimpleLang 语言的代码。

接口代理
-----------------
接口代理是接口的另一种使用方法，会以名称的形式来调用接口内的函数

	interface MyProxy{
		func run(String data)
	}
	
	class MyProxyImp {
		func invoke(String methodName, Any[] args) : Any
	}
	
	MyProxyImp obj()
	
	MyProxy imp = proxy<MyProxy>(obj)	// proxy 是内部函数
	imp.run("Hello")	// 

编译期反射
-------------------

	class A
	A a
	
	for( def i : A ){
		a[i] = xx // 赋值
		if( i.name == "hi" ){ // 编译期比较
	
		}
		i.annotations["CLang"] {
			var n = it["name"]  
		} 
		def T = i
	}

国际化
---------------------
通过翻译表来实现国际化

print( "Hello %t World" )

翻译文件：
	lang.zhCN.ini

[zhCN]
"Hello %t World"="你好 %t 世界"

通过 Lang.set("zhCN") 切换文本
