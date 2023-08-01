#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/token.h"
#include "../../includes/token/tk_constants.h"
#include "../../includes/token/function.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/rightparen.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../includes/sfml/coord_translation.h"
#include "../../includes/sfml/graph_info.h"
#include "../../includes/sfml/constants.h"
#include "../../includes/sfml/graph.h"
#include "../../includes/sfml/coord_translation.h"
#include "../../includes/sfml/system.h"
#include "../../includes/sfml/plot.h"



using namespace std;

bool test_stub(bool debug = false)
{
  Queue<Token*> tokens;
  tokens.push(new Function("tan"));
  tokens.push(new LeftParen());
  tokens.push(new Integer(1));
  tokens.push(new Operator("/"));
  tokens.push(new Function("x"));
  tokens.push(new RightParen());

  ShuntingYard sy(tokens);
  Queue<Token*> rpn_tokens = sy.postfix();
  RPN rpn(rpn_tokens);

  for(int i = -10; i < 10; i+=0.005)
  {
    double rpn_result = rpn(i);

    double result = tanf(1/i);

    cout << "rpn_result: " << rpn_result << endl;
    cout << "result: " << result << endl;
    assert(abs(rpn_result - result) < 0.0001);

  }
  
 
  return true;




}


TEST(TEST_STUB, TestStub) {

  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

