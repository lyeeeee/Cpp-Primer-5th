//
// Created by liyi on 2020/4/3.
//

Sales_data first_item(cin); // 使用 Sales_data(std::istream &is) ; 各成员值从输入流中读取
int main() {
	Sales_data next; // 使用默认构造函数  bookNo = "", cnt = 0, revenue = 0.0

	// 使用 Sales_data(std::string s = "");   bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
	Sales_data last("9-999-99999-9"); 
}
