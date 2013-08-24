#include <iostream>
#include <sstream>
#include <cassert>

#include "single_linked_list.hpp"


using namespace std;




void test_SingleLinkedList_copy_constructor_for_empty_list(void)
{
  SingleLinkedList<int> int_list1;

  SingleLinkedList<int> int_list2(int_list1);

  assert(int_list2.empty());
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_copy_constructor_for_one_element_list(void)
{
  SingleLinkedList<int> int_list1;

  int_list1.push(0);

  SingleLinkedList<int> int_list2(int_list1);

  assert(1 == int_list2.size());
  assert(0 == int_list2[0]);
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_copy_constructor_for_two_element_list(void)
{
  SingleLinkedList<int> int_list1;

  int_list1.push(1);
  int_list1.push(0);

  SingleLinkedList<int> int_list2(int_list1);

  assert(2 == int_list2.size());
  assert(0 == int_list2[0]);
  assert(1 == int_list2[1]);
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_copy_constructor_for_three_element_list(void)
{
  SingleLinkedList<int> int_list1;

  int_list1.push(2);
  int_list1.push(1);
  int_list1.push(0);

  SingleLinkedList<int> int_list2(int_list1);

  assert(3 == int_list2.size());
  assert(0 == int_list2[0]);
  assert(1 == int_list2[1]);
  assert(2 == int_list2[2]);
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_assignment_for_empty_list(void)
{
  SingleLinkedList<int> int_list1;
  SingleLinkedList<int> int_list2;

  int_list2 = int_list1;

  assert(0 == int_list2.size());
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_assignment_for_one_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list2.push(2);

  int_list2 = int_list1;

  assert(1 == int_list2.size());
  assert(1 == int_list2[0]);
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_assignment_for_two_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(3);
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list2.push(2);

  int_list2 = int_list1;

  assert(2 == int_list2.size());
  assert(1 == int_list2[0]);
  assert(3 == int_list2[1]);
  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_assignment_for_three_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(5);
  int_list1.push(3);
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list2.push(2);

  int_list2 = int_list1;

  assert(3 == int_list2.size());
  assert(1 == int_list2[0]);
  assert(5 == int_list2[2]);
  assert(int_list1.equivalent(int_list2));
}





void test_SingleLinkedList_equivalent_for_empty_list(void)
{
  SingleLinkedList<int> int_list1;
  SingleLinkedList<int> int_list2;

  int_list2 = int_list1;

  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_equivalent_for_one_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list2.push(2);

  assert(!int_list1.equivalent(int_list2));

  int_list2 = int_list1;

  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_equivalent_for_two_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(3);
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list2.push(2);

  assert(!int_list1.equivalent(int_list2));

  int_list2 = int_list1;

  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_equivalent_for_three_element_list(void)
{
  SingleLinkedList<int> int_list1;
  int_list1.push(5);
  int_list1.push(3);
  int_list1.push(1);

  SingleLinkedList<int> int_list2;
  int_list1.push(5);
  int_list1.push(3);
  int_list2.push(1);

  assert(!int_list1.equivalent(int_list2));

  int_list2 = int_list1;

  assert(int_list1.equivalent(int_list2));
}




void test_SingleLinkedList_that_a_list_can_be_ostreamed(void)
{
  {
    SingleLinkedList<int> int_list;

    stringstream ss;
    ss << int_list;

    assert(0 == ss.str().compare("{ }"));
  }

  {
    SingleLinkedList<int> int_list;

    int_list.push(0);

    stringstream ss;
    ss << int_list;

    assert(0 == ss.str().compare("{ 0 }"));
  }

  {
    SingleLinkedList<int> int_list;

    int_list.push(1);
    int_list.push(0);

    stringstream ss;
    ss << int_list;

    assert(0 == ss.str().compare("{ 0, 1 }"));
  }

  {
    SingleLinkedList<int> int_list;

    int_list.push(2);
    int_list.push(1);
    int_list.push(0);

    stringstream ss;
    ss << int_list;

    assert(0 == ss.str().compare("{ 0, 1, 2 }"));
  }
}




void test_SingleLinkedList_that_a_new_list_is_empty(void)
{
  SingleLinkedList<int> int_list;

  assert(int_list.empty());
}




void test_SingleLinkedList_that_an_empty_list_can_be_cleared(void)
{
  SingleLinkedList<int> int_list;

  int_list.clear();
  assert(int_list.empty());
}




void test_SingleLinkedList_push_a_single_element(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(1);
  assert(!int_list.empty());

  int_list.clear();
  assert(int_list.empty());
}




void test_SingleLinkedList_at_throws_exception_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  bool caught = false;
  try {
    int_list.at(0);
  }
  catch (const std::out_of_range& e) {
    caught = true;
  }

  assert(caught);
}




void test_SingleLinkedList_at_returns_value_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int expect(1);
  int_list.push(expect);

  bool caught = false;
  try {
    int result = int_list.at(0);

    assert(expect == result);
  }
  catch (const std::out_of_range& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_at_returns_value_for_two_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(1);
  int_list.push(0);

  bool caught = false;
  try {
    int result = int_list.at(0);
    assert(0 == result);

    result = int_list.at(1);
    assert(1 == result);
  }
  catch (const std::out_of_range& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_at_returns_value_for_three_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(2);
  int_list.push(1);
  int_list.push(0);

  bool caught = false;
  try {
    int result = int_list.at(0);
    assert(0 == result);

    result = int_list.at(1);
    assert(1 == result);

    result = int_list.at(2);
    assert(2 == result);
  }
  catch (const std::out_of_range& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_size_returns_value_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  size_t result = int_list.size();

  assert(0 == result);
}




void test_SingleLinkedList_size_returns_value_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);

  size_t result = int_list.size();

  assert(1 == result);
}




void test_SingleLinkedList_size_returns_value_for_two_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);

  size_t result = int_list.size();

  assert(2 == result);
}




void test_SingleLinkedList_size_returns_value_for_three_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);
  int_list.push(2);

  size_t result = int_list.size();

  assert(3 == result);
}




void test_SingleLinkedList_pop_throws_exception_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  bool caught = false;
  try {
    int_list.pop();
  }
  catch (const std::domain_error& e) {
    caught = true;
  }

  assert(caught);
}




void test_SingleLinkedList_push_pop_one_element(void)
{
  SingleLinkedList<int> int_list;

  bool caught = false;
  try {
    int_list.push(1);
    assert(1 == int_list.size());

    int result = int_list.pop();

    assert(1 == result);
    assert(0 == int_list.size());

    assert(int_list.empty());
  }
  catch (const std::domain_error& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_push_pop_two_elements(void)
{
  SingleLinkedList<int> int_list;

  bool caught = false;
  try {
    int_list.push(1);
    assert(1 == int_list.size());

    int_list.push(2);
    assert(2 == int_list.size());

    int result = int_list.pop();
    assert(2 == result);
    assert(1 == int_list.size());

    result = int_list.pop();
    assert(1 == result);
    assert(0 == int_list.size());

    assert(int_list.empty());
  }
  catch (const std::domain_error& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_push_pop_three_elements(void)
{
  SingleLinkedList<int> int_list;

  bool caught = false;
  try {
    int_list.push(1);
    assert(1 == int_list.size());

    int_list.push(2);
    assert(2 == int_list.size());

    int_list.push(3);
    assert(3 == int_list.size());

    int result = int_list.pop();
    assert(3 == result);
    assert(2 == int_list.size());

    result = int_list.pop();
    assert(2 == result);
    assert(1 == int_list.size());

    result = int_list.pop();
    assert(1 == result);
    assert(0 == int_list.size());

    assert(int_list.empty());
  }
  catch (const std::domain_error& e) {
    caught = true;
  }

  assert(!caught);
}




void test_SingleLinkedList_is_sorted_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_is_sorted_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_is_sorted_for_two_element_list(void)
{
  { // test sorted list
    SingleLinkedList<int> int_list;

    int_list.push(1);
    int_list.push(0);

    assert(int_list.is_sorted());
  }

  { // test unsorted list
    SingleLinkedList<int> int_list;

    int_list.push(0);
    int_list.push(1);

    assert(!int_list.is_sorted());
  }
}




void test_SingleLinkedList_is_sorted_for_three_element_list(void)
{
  { // test sorted list
    SingleLinkedList<int> int_list;

    int_list.push(2);
    int_list.push(1);
    int_list.push(0);

    assert(int_list.is_sorted());
  }

  { // test unsorted list
    SingleLinkedList<int> int_list;

    int_list.push(1);
    int_list.push(2);
    int_list.push(0);

    assert(!int_list.is_sorted());
  }
}



void test_SingleLinkedList_is_sorted_for_three_element_list_with_duplicate_values(void)
{
  { // test sorted list
    SingleLinkedList<int> int_list;

    int_list.push(1);
    int_list.push(0);
    int_list.push(0);

    assert(int_list.is_sorted());
  }

  { // test unsorted list
    SingleLinkedList<int> int_list;

    int_list.push(1);
    int_list.push(1);
    int_list.push(2);

    assert(!int_list.is_sorted());
  }
}




void test_SingleLinkedList_bubble_sort_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_bubble_sort_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_bubble_sort_for_two_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);

  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_bubble_sort_for_three_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);
  int_list.push(2);

  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_bubble_sort_for_four_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);
  int_list.push(2);
  int_list.push(3);

  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_bubble_sort_for_four_element_list_with_duplicate_values(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);
  int_list.push(1);
  int_list.push(0);
  int_list.push(1);

  int_list.bubble_sort();

  assert(int_list.is_sorted());
}




void test_SingleLinkedList_merge_sorted_for_empty_list(void)
{
  { // test two empty lists
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.merge_sorted(int_list1);

    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }

  { // test merging empty list into one element list
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(0);

    int_list0.merge_sorted(int_list1);

    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }

  { // test merging one element list into empty list
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list1.push(0);

    int_list0.merge_sorted(int_list1);

    assert(1 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }
}




void test_SingleLinkedList_merge_sorted_for_one_element_list(void)
{
  { // test when list0 is less than list1
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(0);
    int_list1.push(1);

    int_list0.merge_sorted(int_list1);

    assert(2 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }

  { // test when list0 is greater than list1
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(1);
    int_list1.push(0);

    int_list0.merge_sorted(int_list1);

    assert(2 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }
}




void test_SingleLinkedList_merge_sorted_for_two_element_list(void)
{
  SingleLinkedList<int> int_list0;
  SingleLinkedList<int> int_list1;

  int_list0.push(3);
  int_list0.push(1);

  int_list1.push(2);
  int_list1.push(0);

  int_list0.merge_sorted(int_list1);

  assert(4 == int_list0.size());
  assert(int_list0.is_sorted());
  assert(int_list1.empty());
}




void test_SingleLinkedList_merge_sorted_for_three_element_list(void)
{
  { // test unique elements
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(5);
    int_list0.push(3);
    int_list0.push(1);

    int_list1.push(4);
    int_list1.push(2);
    int_list1.push(0);

    int_list0.merge_sorted(int_list1);

    assert(6 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }


  { // test duplicate elements
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(4);
    int_list0.push(3);
    int_list0.push(1);

    int_list1.push(3);
    int_list1.push(2);
    int_list1.push(0);

    int_list0.merge_sorted(int_list1);

    assert(6 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }


  { // test identical lists
    SingleLinkedList<int> int_list0;
    SingleLinkedList<int> int_list1;

    int_list0.push(3);
    int_list0.push(2);
    int_list0.push(1);

    int_list1.push(3);
    int_list1.push(2);
    int_list1.push(1);

    int_list0.merge_sorted(int_list1);

    assert(6 == int_list0.size());
    assert(int_list0.is_sorted());
    assert(int_list1.empty());
  }
}




void test_SingleLinkedList_reverse_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.reverse();

  assert(int_list.empty());
}




void test_SingleLinkedList_reverse_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);

  int_list.reverse();

  assert(0 == int_list.at(0));
}




void test_SingleLinkedList_reverse_for_two_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(1);
  int_list.push(0);

  int_list.reverse();

  assert(1 == int_list.at(0));

  int_list.reverse();

  assert(0 == int_list.at(0));
}




void test_SingleLinkedList_reverse_for_three_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(2);
  int_list.push(1);
  int_list.push(0);

  int_list.reverse();

  assert(2 == int_list.at(0));

  int_list.reverse();

  assert(0 == int_list.at(0));
}




void test_SingleLinkedList_is_cyclic_for_empty_list(void)
{
  SingleLinkedList<int> int_list;

  assert(!int_list.is_cyclic());
}




void test_SingleLinkedList_is_cyclic_for_one_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(0);

  assert(!int_list.is_cyclic());
}




void test_SingleLinkedList_is_cyclic_for_two_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(1);
  int_list.push(0);

  assert(!int_list.is_cyclic());
}




void test_SingleLinkedList_is_cyclic_for_three_element_list(void)
{
  SingleLinkedList<int> int_list;

  int_list.push(2);
  int_list.push(1);
  int_list.push(0);

  assert(!int_list.is_cyclic());
}




int main(int argc, char* argv[])
{
  test_SingleLinkedList_copy_constructor_for_empty_list();
  test_SingleLinkedList_copy_constructor_for_one_element_list();
  test_SingleLinkedList_copy_constructor_for_two_element_list();
  test_SingleLinkedList_copy_constructor_for_three_element_list();

  test_SingleLinkedList_assignment_for_empty_list();
  test_SingleLinkedList_assignment_for_one_element_list();
  test_SingleLinkedList_assignment_for_two_element_list();
  test_SingleLinkedList_assignment_for_three_element_list();

  test_SingleLinkedList_equivalent_for_empty_list();
  test_SingleLinkedList_equivalent_for_one_element_list();
  test_SingleLinkedList_equivalent_for_two_element_list();
  test_SingleLinkedList_equivalent_for_three_element_list();

  test_SingleLinkedList_that_a_list_can_be_ostreamed();
  test_SingleLinkedList_that_a_new_list_is_empty();
  test_SingleLinkedList_that_an_empty_list_can_be_cleared();

  test_SingleLinkedList_push_a_single_element();

  test_SingleLinkedList_at_throws_exception_for_empty_list();
  test_SingleLinkedList_at_returns_value_for_one_element_list();
  test_SingleLinkedList_at_returns_value_for_two_element_list();
  test_SingleLinkedList_at_returns_value_for_three_element_list();

  test_SingleLinkedList_size_returns_value_for_empty_list();
  test_SingleLinkedList_size_returns_value_for_one_element_list();
  test_SingleLinkedList_size_returns_value_for_two_element_list();
  test_SingleLinkedList_size_returns_value_for_three_element_list();

  test_SingleLinkedList_pop_throws_exception_for_empty_list();
  test_SingleLinkedList_push_pop_one_element();
  test_SingleLinkedList_push_pop_two_elements();
  test_SingleLinkedList_push_pop_three_elements();

  test_SingleLinkedList_is_sorted_for_empty_list();
  test_SingleLinkedList_is_sorted_for_one_element_list();
  test_SingleLinkedList_is_sorted_for_two_element_list();
  test_SingleLinkedList_is_sorted_for_three_element_list();
  test_SingleLinkedList_is_sorted_for_three_element_list_with_duplicate_values();

  test_SingleLinkedList_bubble_sort_for_empty_list();
  test_SingleLinkedList_bubble_sort_for_one_element_list();
  test_SingleLinkedList_bubble_sort_for_two_element_list();
  test_SingleLinkedList_bubble_sort_for_three_element_list();
  test_SingleLinkedList_bubble_sort_for_four_element_list();
  test_SingleLinkedList_bubble_sort_for_four_element_list_with_duplicate_values();

  test_SingleLinkedList_merge_sorted_for_empty_list();
  test_SingleLinkedList_merge_sorted_for_one_element_list();
  test_SingleLinkedList_merge_sorted_for_two_element_list();
  test_SingleLinkedList_merge_sorted_for_three_element_list();

  test_SingleLinkedList_reverse_for_empty_list();
  test_SingleLinkedList_reverse_for_one_element_list();
  test_SingleLinkedList_reverse_for_two_element_list();
  test_SingleLinkedList_reverse_for_three_element_list();

  test_SingleLinkedList_is_cyclic_for_empty_list();
  test_SingleLinkedList_is_cyclic_for_one_element_list();
  test_SingleLinkedList_is_cyclic_for_two_element_list();
  test_SingleLinkedList_is_cyclic_for_three_element_list();

  cout << __FILE__ << " PASSED"<< endl;
}
