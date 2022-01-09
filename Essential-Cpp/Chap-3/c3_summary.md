## Chapater 3

### Functions

- 泛型算法`find()`，常用于搜索无序集合

    ```cpp
    while ((iter = find(iter, vec.end(), val)) != vec.end()) {
        // ...
    }
    ```

- `find_if()`

    ```cpp
    while ((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()) {
        // ...
    }
    ```

- 泛型算法 `sort()`

- 泛型算法 `replace()`

- 泛型算法 `merge()`...

- `binary_search()`用于有序集合的搜索

    ```cpp
    sort(temp.begin(), temp.end());
    return binary_search(vec.begin(), vec.end(), elem);
    ```

- `count()`返回数值相符的元素数目（

- `search()`对比某个容器内是否存在某子序列。
    若子序列存在，返回一个 iterator 指向子序列起始处，否则返回一个 iterator 指向容器末尾。

- 泛型算法 `max_element()`

    ```cpp
    int max_value = max_element(vec.begin(), vec.end());
    ```

- `copy()`接受两个 iterator，标示出复制范围，第三个`iterator`指向复制行为的目的地（容器的第一个元素）。

    ```cpp
    copy(vec.begin(), vec.end(), temp.begin());
    ```

- 泛型算法 `transform()`

    ```cpp
    // 将一个 Pell 序列加到 Fibonacci 序列上
    transform(fibon.begin(), fibon.end(), pell.begin(), fib_plus_pell.begin(), plus<int>());
    ```

- （练习 3.3）`getline()`从文件中读取一行内容，第三参数指定行末字符第三参数的默认值是换行符

    ```cpp
    while (get_line(nameFile, textline)) {
        // ...
    }
    ```

---

<br />

### Iterator Class 内置运算符

- `++ * == !=`

---

<br />

### 容器的共通操作函数

- `== != =` （equality, inequality, assignment）

- `empty()`返回 `true` `false`

- `size()`返回容器内目前的元素个数

- `clear()`删除所有元素

    ```cpp
    t.clear();		// 清除 t 的元素, 此后 t.empty() 会返回 true, t.size() 会返回 0
    ```

- `begin()`返回一个 iterator，指向容器的第一个元素

- `end()`返回一个 iterator，指向容器的最后一个元素的下一位置

- `insert()`将单一或某个范围内的元素插入容器中

- `erase()`将容器内的单一元素或某个范围内的元素删除

---

<br />

### 操作函数

- 特殊化插入：`push_front()`, `push_back()`

- 特殊化删除：`pop_front()`, 

- map、set 的 `find()`函数

    ```cpp
    map<string, int>::iterator it = words.find("vermeer");
    // 若 key 已放在 map 中, find() 会返回一个 iterator, 指向 key/value 形成的 pair
    ```

- map 的 `count()`函数

    ```cpp
    if (words.count(search_word))	// 存在
        count = words[search_word];
    ```

- `substr()`

    ```cpp
    fam_name = text_line.substr(prev_pos, end_pos);		// 提取从 prev_pos 开始的 end_pos 个字符
    ```

---

<br />

### 容器

- vector（顺序容器）

- list（顺序容器）

- deque（顺序容器）

- map（关联容器）

    > 成员 `first`, `second`

- set（关联容器）

---

<br />

### Function Object

- 头文件

    ```cpp
    #include <functional>
    ```

- 算术运算：

    >`plus<type>` `minus<type>` `negate<type>` `multiplies<type>` `divides<type>` `modules<type>`

- 关系运算：

    > `less<type>` `less_equal<type>` `greater<type>` `greater_equal<type>` 
    > `equal_to<type>` `not_euqal_to<type>`

    ```cpp
    binary_search(vec.begin(), vec.end(), elem, greater<int>());	// greater<int>() 给出一个对象
    ```

- 逻辑运算：

    > `logical_and<type>` `logical_or<type>` `logical_not<type>`

---

<br />

### Function Object Adapter

```cpp
#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS // 报错时考虑添加
```

- `bind1st`（binder adaption）会将指定值绑定至第一操作数

- `bind2nd`（binder adaption）会将指定值绑定至第二操作数

    ```cpp
    while ((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()) {
        nevc.push_back(*iter);
        iter++;
    }
    ```

- `not1`（negator）可对 unary function object 的真伪取反

- `not2`（negator）可对 binary function object 的真伪取反

    ```cpp
    // 例如要找出 "大于或等于" 10 的元素, 则可将 functional object less<int>() 的运算结果取反
    while ((iter = find_if(iter, vec.end(), not1(bind2nd(less<int>, 10)))) != vec.end()) {
        // ...
    }
    ```

---

<br />

### Iterator Inserter

- 头文件

    ```cpp
    #include <iterator>
    ```

- `back_inserter()`以容器的`push_back()`函数取代赋值运算符。

    ```cpp
    vector<int> result_vec;
    unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec));
    ```

- `inserter()`容器的`insert()`函数取代赋值运算符。

    ```cpp
    vector<string> svec_res;
    // ... (对 sevc_res 一些填充)
    unique_copy(svec.begin(), svec.end(), inserter(svec_res, svec_res.end()));	// 在末尾插入
    ```

- `front_inserter()`会以容器的`push_front()`函数取代赋值运算符。（适用于 list 和 deque）

    ```cpp
    list<int> ilist_clone;
    copy(ilist.begin(), ilist(), front_inserter(ilist_clone));
    ```

---

<br />

### iostream Iterator

- 头文件

    ```cpp
    #include <iterator>
    ```

- 利用 `istream_iterator`从标准输入设备读取字符串

    ```cpp
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;
    copy(is, eof, back_insterter(text));
    ```

- 利用 `ostream_iterator`

    ```cpp
    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
    ```

    



