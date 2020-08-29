#include "Stack.h"
#include "ParenthesesMatch.h"

#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::logic_error;


template <typename elemType>
bool checkTest(string testName, elemType whatItShouldBe, elemType whatItIs);
bool testConstructor();
bool testPush();
bool testOutput();
bool testPop();
bool testClear();
bool testDeepCopy();
bool testParentheses();
void testOther();

int main()
{
   int passed = 0;
   passed += testConstructor();
   passed += testPush();
   passed += testOutput();
   passed += testPop();
   passed += testClear();
   passed += testDeepCopy();
   passed += testParentheses();

   if(passed < 7){
      cout << "You have passed " << passed << "/7 required tests" << endl;
      cout << "Please go back and fix your code so that it passes all required tests" << endl;
      cout << "Score: 0/60" << endl;
      exit(1);
   }
   else{
      cout << "Congratulations! You have passed all required test cases" << endl;
      cout << "Score: 60/60" << endl;
   }

   testOther();

   return 0;
}

bool testConstructor(){
   bool passed = true;
   cout << "-------------Test Constructor--------------" << endl;
   Stack<int> intStack;
   passed &= checkTest("Constructor 1", intStack.size(), 0);
   passed &= checkTest("Constructor 2", intStack.empty(), true);
   Stack<double> dStack;
   passed &= checkTest("Constructor 3", dStack.size(), 0);
   passed &= checkTest("Constructor 4", dStack.empty(), true);
   return passed;
}

bool testPush(){
   bool passed = true;
   cout << "-------------Test Push--------------" << endl;
   Stack<int> intStack;
   intStack.push(3);
   passed &= checkTest("Push 1", intStack.size(), 1);
   passed &= checkTest("Push 2", intStack.top(), 3);
   passed &= checkTest("Push 3", intStack.empty(), false);
   intStack.push(8);
   passed &= checkTest("Push 4", intStack.size(), 2);
   passed &= checkTest("Push 5", intStack.top(), 8);
   intStack.push(39);
   passed &= checkTest("Push 6", intStack.size(), 3);
   passed &= checkTest("Push 7", intStack.top(), 39);
   Stack<char> charStack;
   charStack.push('d');
   charStack.push('r');
   charStack.push('y');
   passed &= checkTest("Push 8", charStack.top(), 'y');
   return passed;
}

bool testOutput(){
   bool passed = true;
   cout << "-------------Test Output--------------" << endl;
   Stack<int> intStack;
   ostringstream output;
   output << intStack;
   passed &= checkTest("Output 1", output.str(), string(""));
   output.str("");
   output.clear();
   intStack.push(4);
   output << intStack;
   passed &= checkTest("Output 2", output.str(), string("4"));
   output.str("");
   output.clear();
   intStack.push(8);
   output << intStack;
   passed &= checkTest("Output 3", output.str(), string("4->8"));
   output.str("");
   output.clear();
   intStack.push(1);
   output << intStack;
   passed &= checkTest("Output 4", output.str(), string("4->8->1"));
   output.str("");
   output.clear();
   intStack.push(5);
   output << intStack;
   passed &= checkTest("Output 5", output.str(), string("4->8->1->5"));
   output.str("");
   output.clear();
   return passed;
}

bool testPop(){
   bool passed = true;
   cout << "-------------Test Pop--------------" << endl;
   Stack<int> intStack;
   intStack.push(3);
   intStack.pop();
   passed &= checkTest("Pop 1", intStack.size(), 0);
   passed &= checkTest("Pop 2", intStack.empty(), true);
   intStack.push(2);
   passed &= checkTest("Pop 3", intStack.top(), 2);
   intStack.push(6);
   intStack.push(1);
   intStack.pop();
   passed &= checkTest("Pop 4", intStack.top(), 6);
   intStack.push(3);
   intStack.push(7);
   intStack.pop();
   passed &= checkTest("Pop 5", intStack.top(), 3);
   ostringstream output;
   output << intStack;
   passed &= checkTest("Pop 6", output.str(), string("2->6->3"));
   output.str("");
   output.clear();
   intStack.pop();
   passed &= checkTest("Pop 7", intStack.top(), 6);
   intStack.pop();
   passed &= checkTest("Pop 8", intStack.top(), 2);
   intStack.pop();
   passed &= checkTest("Pop 9", intStack.size(), 0);
   passed &= checkTest("Pop 10", intStack.empty(), true);
   return passed;
}

bool testClear(){
   bool passed = true;
   cout << "-------------Test Clear--------------" << endl;
   Stack<int> intStack;
   intStack.push(5);
   intStack.clear();
   passed &= checkTest("Clear 1", intStack.size(), 0);
   passed &= checkTest("Clear 2", intStack.empty(), true);
   ostringstream output;
   output << intStack;
   passed &= checkTest("Clear 3", output.str(), string(""));
   output.str("");
   output.clear();
   intStack.push(4);
   intStack.push(374);
   intStack.push(234);
   intStack.clear();
   passed &= checkTest("Clear 4", intStack.size(), 0);
   passed &= checkTest("Clear 5", intStack.empty(), true);
   output << intStack;
   passed &= checkTest("Clear 6", output.str(), string(""));
   output.str("");
   output.clear();
   intStack.push(4);
   intStack.push(374);
   intStack.pop();
   intStack.clear();
   passed &= checkTest("Clear 7", intStack.size(), 0);
   passed &= checkTest("Clear 8", intStack.empty(), true);
   output << intStack;
   passed &= checkTest("Clear 9", output.str(), string(""));
   output.str("");
   output.clear();
   return passed;
}

bool testDeepCopy(){
   bool passed = true;
   cout << "-------------Test Deep Copy--------------" << endl;
   Stack<int> intStack;
   intStack.push(12);
   intStack.push(2);
   intStack.push(15);
   Stack<int> copiedStack(intStack);
   passed &= checkTest("Deep Copy 1", intStack.size(), 3);
   passed &= checkTest("Deep Copy 2", copiedStack.size(), 3);
   ostringstream output;
   output << intStack;
   passed &= checkTest("Deep Copy 3", output.str(), string("12->2->15"));
   output.str("");
   output.clear();
   output << copiedStack;
   passed &= checkTest("Deep Copy 4", output.str(), string("12->2->15"));
   output.str("");
   output.clear();
   intStack.push(8);
   output << intStack;
   passed &= checkTest("Deep Copy 5", output.str(), string("12->2->15->8"));
   output.str("");
   output.clear();
   output << copiedStack;
   passed &= checkTest("Deep Copy 6", output.str(), string("12->2->15"));
   output.str("");
   output.clear();
   intStack.push(18);
   copiedStack = intStack;
   passed &= checkTest("Deep Copy 7", intStack.size(), 5);
   passed &= checkTest("Deep Copy 8", copiedStack.size(), 5);
   copiedStack.pop();
   output << intStack;
   passed &= checkTest("Deep Copy 9", output.str(), string("12->2->15->8->18"));
   output.str("");
   output.clear();
   output << copiedStack;
   passed &= checkTest("Deep Copy 10", output.str(), string("12->2->15->8"));
   output.str("");
   output.clear();
   return passed;
}

bool testParentheses(){
   bool passed = true;
   cout << "-------------Test Parentheses--------------" << endl;
   passed &= checkTest("Parentheses 1", parenthesesMatch("()"), true);
   passed &= checkTest("Parentheses 2", parenthesesMatch("("), false);
   passed &= checkTest("Parentheses 3", parenthesesMatch("(())"), true);
   passed &= checkTest("Parentheses 4", parenthesesMatch("()()"), true);
   passed &= checkTest("Parentheses 5", parenthesesMatch("(()"), false);
   passed &= checkTest("Parentheses 6", parenthesesMatch(")()("), false);
   passed &= checkTest("Parentheses 7", parenthesesMatch("(4+3)"), true);
   passed &= checkTest("Parentheses 8", parenthesesMatch("(2-1"), false);
   passed &= checkTest("Parentheses 9", parenthesesMatch("(18*(2+6)-7)"), true);
   passed &= checkTest("Parentheses 10", parenthesesMatch("(4*2)+(12-5)"), true);
   passed &= checkTest("Parentheses 11", parenthesesMatch("(13/(2+5)"), false);
   passed &= checkTest("Parentheses 12", parenthesesMatch("1+3)*(8/2)-(4+2"), false);
   return passed;
}

void testOther(){
   int passed = 0;
   cout << "-------------Test Other--------------" << endl;
   Stack<int> intStack;
   intStack.push(9);
   passed += checkTest("Other 1", intStack.topPop(), 9);
   intStack.push(8);
   intStack.push(7);
   intStack.push(6);
   passed += checkTest("Other 2", intStack.topPop(), 6);
   intStack.push(5);
   intStack.push(4);
   intStack.push(3);
   intStack.pop(2);
   passed += checkTest("Other 3", intStack.size(), 3);
   passed += checkTest("Other 4", intStack.top(), 5);
   intStack.push(1);
   intStack.pop(3);
   passed += checkTest("Other 5", intStack.size(), 1);
   passed += checkTest("Other 6", intStack.top(), 8);

   //Boundary cases
   intStack.clear();
   intStack.clear(); //clear an empty list
   passed += checkTest("Other 7", string("No errors"), string("No errors"));
   intStack.pop(); //pop an empty list
   passed += checkTest("Other 8", string("No errors"), string("No errors"));
   passed += checkTest("Other 9", intStack.size(), 0);
   passed += checkTest("Other 10", intStack.empty(), true);
   intStack.pop(3); //pop an empty list
   passed += checkTest("Other 11", string("No errors"), string("No errors"));
   passed += checkTest("Other 12", intStack.size(), 0);
   passed += checkTest("Other 13", intStack.empty(), true);
   try{
      intStack.top();
      passed += checkTest("Other 14", string("No error"), string("logic_error"));
   }
   catch(logic_error& e){
      passed += checkTest("Other 14", string("logic_error"), string("logic_error"));
   }
   try{
      intStack.topPop();
      passed += checkTest("Other 15", string("No error"), string("logic_error"));
   }
   catch(logic_error& e){
      passed += checkTest("Other 15", string("logic_error"), string("logic_error"));
   }

   cout << "Passed " << passed << "/15 optional tests" << endl;
   cout << "Score: " << passed/15.0*20 << endl;
}

//This helps with testing, do not modify.
template<class elemType>
bool checkTest(string testName, elemType actual, elemType expected) {

	if (actual == expected) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " ** " << endl << "   Output was "<< actual << endl << "   Output should have been " << expected << endl;
		return false;
	}
}
