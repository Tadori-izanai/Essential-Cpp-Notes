## Chapter1

|  对象  |     类     |   头文件   | 说明、举例                                                   |
| :----: | :--------: | :--------: | :----------------------------------------------------------- |
| `cout` |     -      | `iostream` | 使用 `<<`定向到其中                                          |
| `cin`  |     -      | `iostream` | 使用`>>`将输出内容定向到具体对象                             |
| `cerr` |     -      | `iostream` |                                                              |
|   -    |  `string`  |  `string`  | 字符串类                                                     |
|   -    | `complex`  | `complex`  | `complex<double> purei(0, 7);`                               |
|   -    |  `vector`  |  `vector`  | `vector<int> pell_seq(seq_size);`                            |
|   -    | `ofstream` | `fstream`  | "w": `ofstream outfile("file_name");`<br />"a": `ofstream outfile("file_name", ios_base::app);` |
|   -    | `ifstream` | `fstream`  | "r": `ifstream infile("file_name");`                         |
|   -    | `fstream`  | `fstream`  | "a": `fstream iofile("file_name", ios_base::in|ios_base::app);` |



### 运算符

`<<`, `>>`, `.`, `->`



### Class object 操作

|     操作      |          举例           | 说明                                         |
| :-----------: | :---------------------: | -------------------------------------------- |
|   `empty()`   |   `fibonacci.empty()`   | 判断 vector `fibonacci`是否为空              |
|   `seekg()`   |    `iofile.seekg(0)`    | 开始读取`iofile`之前，将文件重新定位至起始处 |
|   `size()`    |      `ivec.size()`      | vector `ivec`的 size                         |
|  `length()`   |     `word.length()`     | string `word`的长度，可用`size()`代替        |
| `push_back()` | `ivec.push_back(ival);` | 在 vector `ivec`中添加新元素，元素值为`ival` |
|   `begin()`   |     `text.begin()`      | 返回指向容器最开始位置数据的指针             |
|    `end()`    |      `text.end()`       | 返回指向容器 (最后一个数据单元 + 1) 的指针   |



### 操作符（manipulator）

|      操作符       | 说明、举例                                                   |
| :---------------: | :----------------------------------------------------------- |
|      `endl`       | 插入一个换行符，清除缓冲区中的内容                           |
|       `hex`       | 十六进制                                                     |
|       `oct`       | 八进制                                                       |
| `setprecision(n)` | 设浮点数显示精度为 n                                         |
|     `setw(n)`     | 控制读入的字符数量上限为 n<br />`cin >> setw(size) >> name;`   //（限制 string `name`字符上限为 `size`） |



### 函数

|   函数    |   头文件    | 说明、举例                                                   |
| :-------: | :---------: | ------------------------------------------------------------ |
| `srand()` |  `cstdlib`  | `srand(seq_cnt)`                                             |
| `rand()`  |  `cstdlib`  | 每次调用`rand()`，生成随机数                                 |
| `sort()`  | `algorithm` | `sort(text.begin(), text.end());`（对 vector `text`中的元素排序） |

