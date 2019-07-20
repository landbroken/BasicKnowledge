#include"stdafx.h"

/*C++常用算法，STL常用算法（排序、合并、搜索和分区）*/
/*
1、C++ sort（STL sort）排序算法

2、C++ stable_sort(STL stable_sort)排序算法

3、C++ partial_sort(STL partial_sort)排序算法
假设有一个容器，它保存了 100 万个数值，但我们只对其中最小的 100 个感兴趣。可以对容器的全部内容排序，然后选择前 100 个元素，但这可能有点消耗时间。这时候需要使用部分排序，只需要这些数中的前100个是有序放置的。

4、C++ nth_element(STL nth_element)排序算法
nth_element() 算法和 partial_sort() 不同。应用的范围由它的第一个和第三个参数指定。第二个参数是一个指向第 n 个元素的迭代器。如果这个范围内的元素是完全有序的，nth_dement() 的执行会导致第 n 个元素被放置在适当的位置。这个范围内，在第 n 个元素之前的元素都小于第 n 个元素，而且它后面的每个元素都会比它大。算法默认用 < 运算符来生成这个结果。

5、C++ is_sorted(STL is_sorted)排序算法
*/

/*
6、C++ merge和inplace_merge（STL merge和inplace_merge）算法

std::vector<int> these {2, 15, 4, 11, 6r 7};//1st input to merge
std::vector<int> those {5, 2, 3, 2, 14, 11, 6}; // 2nd input to merge
std::stable_sort(std:rbegin(these), std::end(these),std::greatero ());// Sort 1st range in descending sequence
std::stable_sort(std::begin(those), std::end(those), std::greater<>()); // Sort 2nd range
std::vector<int> result(these.size() + those.size() + 10);//Plenty of room for results
auto end_iter = std::merge(std::begin(these), std::end(these),std::begin(those), std::end(those),std::begin (result), std::greater<>());// Merge 1st range and 2nd range into result
std:: copy (std::begin (result), end_iter, std::ostream_iterator<int>{std::cout, " "});
*/

/*
7、C++ find（STL find）查找算法

8、C++ find_if（STL find_if）查找算法

int value {5};
auto iter1 = std::find_if(std::begin(numbers), std::end(numbers),[value](int n) { return n > value; });
if(iter1 != std::end(numbers))
std::cout << *iter1 << " was found greater than " << value << ".\n";

9、C++ find_if_not（STL find_if_not）查找算法

10、C++ find_first_of(STL find_first_of)查找算法

11、C++ adjacent_find(STL adjacent_find)算法使用
adjacent_find() 算法可以用来搜索序列中两个连续相等的元素。用 == 运算符来比较连续的一对元素，返回的迭代器指向前两个相等元素中的第一个。如果没有一对相等的元素，这个算法返回这个序列的结束迭代器。

12、C++ find_end(STL find_end)

13、C++ search(STL search)
在查找序列的子序列方面，search() 算法和 find_end() 算法相似，但它所查找的是第一个匹配项而不是最后一个

14、C++ search_n（STL search_n）搜索算法
*/

/*
15、C++ partition(STL partition)算法
在序列中分区元素会重新对元素进行排列，所有使给定谓词返回 true 的元素会被放在所有使谓词返回 false 的元素的前面。这就是 partition() 算法所做的事。

partition 的前两个参数是定义被分区序列范围的正向迭代器，第三个参数是一个谓词。下面展示如何使用 partition() 来重新排列序列中的值，所有小于平均值的元素会被放在所有大于平均值的元素的后面：

std::vector<double> temperatures {65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50};
std::copy(std::begin(temperatures), std::end(temperatures), //List the values
std::ostream_iterator<double>{std::cout, " "});
std::cout << std::endl;
auto average = std::accumulate(std::begin(temperatures),std::end(temperatures), 0.0)/temperatures.size();
std::cout << "Average temperature: "<< average << std::endl;
std::partition(std::begin(temperatures), std::end(temperatures),[average](double t) { return t < average; });
std::copy(std::begin(temperatures), std::end(temperatures),std::ostream_iterator<doiible>{std::cout, " "});
std::cout << std::endl;

这段代码会输出下面这些内容：
65 75 56 48 31 28 32 29 40 41 44 50
Average temperature: 44.9167
44 41 40 29 31 28 32 48 56 75 65 50

16、C++ partition_copy(STL partition_copy)

17、C++ partition_point(STL partition_point)算法
*/

/*
18、C++ binary_search(STL binary_search)二分查找
19、C++ lower_bound(STL lower_bound)二分查找
20、C++ upper_bound(STL upper_bound)二分查找
21、C++ equel_range(STL equal_range)二分查找
22、C++(STL) all_of、any_of及none_of
*/

/*
23、C++ equal(STL equal)比较算法
24、C++ mismatch(STL mismatch)
*/

/*
25、C++（STL） lexicographical_compare字符串排序算法

两个字符串的字母排序是通过从第一个字符开始比较对应字符得到的。第一对不同的对应字符决定了哪个字符串排在首位。字符串的顺序就是不同字符的顺序。如果字符串的长度相同，而且所有的字符都相等，那么这些字符串就相等。如果字符串的长度不同，短字符串的字符序列和长字符串的初始序列是相同的，那么短字符串小于长字符串。因此 “age” 在“beauty” 之前，“a lull” 在 “a storm” 之前。显然，“the chicken” 而不是 “the egg” 会排在首位。

对于任何类型的对象序列来说，字典序都是字母排序思想的泛化。从两个序列的第一个元素开始依次比较对应的元素，前两个对象的不同会决定序列的顺序。显然，序列中的对象必须是可比较的。

lexicographical_compare()算法可以比较由开始和结束迭代器定义的两个序列。它的前两个参数定义了第一个序列，第 3 和第 4 个参数分别是第二个序列的开始和结束迭代器。默认用 < 运算符来比较元素，但在需要时，也可以提供一个实现小于比较的函数对象作为可选的第 5 个参数。如果第一个序列的字典序小于第二个，这个算法会返回 true，否则返回 false。所以，返回 false 表明第一个序列大于或等于第二个序列。

序列是逐个元素比较的。第一对不同的对应元素决定了序列的顺序。如果序列的长度不同，而且短序列和长序列的初始元素序列匹配，那么短序列小于长序列。长度相同而且对应元素都相等的两个序列是相等的。空序列总是小于非空序列。下面是一个使用 lexicographical_compare() 的示例：
std::vector<string> phrase1 {"the", "tigers", "of", "wrath"};
std::vector<string> phrase2 {"the", "horses", "of", "instruction"};
auto less = std::lexicographical_compare (std::begin (phrase1), std: :end (phrase1),
std::begin(phrase2), std::end(phrase2)); std::copy(std::begin(phrase1), std::end(phrase1), std::ostream_iterator<string>{std::cout, " "});
std::cout << (less ? "are":"are not") << " less than ";
std::copy(std::begin(phrase2), std::end(phrase2), std::ostream_iterator <string>{std::cout, " "});
std::cout << std::endl;
因为这些序列的第二个元素不同，而且“tigers”大于“horses”，这段代码会生成如下 输出：
the tigers of wrath are not less than the horses of instruction

26、C++ next_permutation(STL next_permutation)算法
27、C++ prev_permutation(STL prev_permutation)算法
28、C++ is_permutation（STL is_permutation）算法
*/

/*
C++ copy_n(STL copy_n)算法
C++ copy_if(STL copy_if)算法
C++ copy_backward(STL copy_backward)
C++ reverse_copy(STL reverse_copy)
*/

/*
C++ unique(STL unique)算法
unique() 算法可以在序列中原地移除重复的元素，这就要求被处理的序列必须是正向迭代器所指定的。在移除重复元素后，它会返回一个正向迭代器作为新序列的结束迭代器。
*/

/*
C++ replace,replace_if和replace_copy函数
replace() 算法会用新的值来替换和给定值相匹配的元素。它的前两个参数是被处理序列的正向迭代器，第 3 个参数是被替换的值，第 4 个参数是新的值。下面展示了它的用法:
std::deque<int> data {10, -5, 12, -6, 10, 8, -7, 10, 11};
std::replace(std::begin(data), std::end(data), 10, 99);
// Result: 99 -5 12 -6 99 8 -7 99 11
*/