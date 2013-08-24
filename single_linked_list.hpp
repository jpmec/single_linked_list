/// A simple singly-linked list implementation.
/// For demonstration purposes only.
///
/// Written by Joshua Petitt
/// https://github.com/jpmec/single_linked_list
/// MIT license


#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <stdexcept>
#include <iostream>
#include <cassert>




/// A simple single linked list implementation.
/// Follows naming conventions of std::list when possible.
template <typename T>
class SingleLinkedList
{
public:

  /// Default constructor.
  SingleLinkedList()
    : head(NULL)
  {
  }


  /// Copy constructor.
  SingleLinkedList(const SingleLinkedList& other)
    : head(NULL)
  {
    this->deep_copy(other);
  }


  /// Virtual destructor.
  virtual ~SingleLinkedList()
  {
    clear();
  }


  /// Assignment
  SingleLinkedList& operator=(const SingleLinkedList& other)
  {
    return this->deep_copy(other);
  }


  /// Returns true if the list is empty.
  bool empty(void) const
  {
    return NULL == this->head;
  }


  /// Clear the contents of the list.
  void clear(void)
  {
    Node* this_node = this->head;

    while (NULL != this_node)
    {
      Node* const next_node = this_node->next;
      delete(this_node);
      this_node = next_node;
    }

    this->head = NULL;
  }


  /// Get value at given index.
  /// Throws std::out_of_range exception if given an index out of range.
  T at(size_t i) const
  {
    if (this->empty())
    {
      throw std::out_of_range("i");
    }

    Node* node = this->head;

    for (; i > 0; --i)
    {
      node = node->next;

      if (NULL == node)
      {
        throw std::out_of_range("i");
      }
    }

    return node->data;
  }


  // Index operator.
  // Returns value of element at position i.
  T operator[](size_t i) const
  {
    return this->at(i);
  }


  /// Get the number of elements in the list.
  size_t size(void) const
  {
    size_t i = 0;

    Node* node = this->head;
    while (node)
    {
      ++i;
      node = node->next;
    }

    return i;
  }


  /// Push an element onto the head of the list.
  void push(T value)
  {
    Node* next = this->head;
    this->head = new Node(value, next);
  }


  /// Pop an element from the head of the list.
  /// Throws std::domain_error if list is empty.
  T pop(void)
  {
    if (this->empty())
    {
      throw std::domain_error("");
    }

    Node* node = this->head;
    this->head = node->next;

    const T result = node->data;
    delete(node);

    return result;
  }


  /// Returns true if the list is sorted.
  bool is_sorted(void) const
  {
    if (2 > this->size())
    {
      return true;
    }

    Node* n0 = this->head;
    Node* n1 = n0->next;

    do
    {
      const T v0(n0->data);
      const T v1(n1->data);

      // TODO USE COMPARISON FUNCTION FOR INEQUALITY CHECK
      if (v1 < v0)
      {
        return false;
      }

      n0 = n1;
      n1 = n1->next;

    } while(NULL != n1);

    return true;
  }


  /// A simple bubble sort implementation.
  /// Expect O(n^2) performance.
  /// Will be faster for almost sorted lists.
  void bubble_sort(void)
  {
    if (2 > this->size())
    {
      return;
    }

    // iterate until no swaps occur
    size_t swap_count = 0;
    do
    {
      swap_count = 0;

      // make single pass over list,
      // swapping adjacent elements that fail comparison
      Node* n0_prev = NULL;
      Node* n0 = this->head;
      Node* n1 = n0->next;
      do
      {
        // compare
        const T v0(n0->data);
        const T v1(n1->data);

        // TODO USE COMPARISON FUNCTION FOR INEQUALITY CHECK
        if (v1 < v0)
        {
          // take care of the head
          if (this->head == n0)
          {
            this->head = n1;
          }

          // swap
          this->swap_adjacent(n0_prev, n0, n1);
          ++swap_count;
        }

        // increment
        Node* next = n1->next;
        n0_prev = n0;
        n0 = n1;
        n1 = next;

      } while (NULL != n1);

    } while (swap_count);
  }


  /// Merge sorted list into this list.
  /// Don't allocate any new nodes.
  /// After function, this will contain all nodes, list will be empty.
  /// Expect O(n) performance.
  void merge_sorted(SingleLinkedList& list)
  {
    assert(this->is_sorted());
    assert(list.is_sorted());

    if (list.empty())
    {
      return;
    }

    if (this->empty())
    {
      this->head = list.head;
      list.head = NULL;
      return;
    }

    Node* this_node = this->head;
    Node* list_node = list.head;

    // select head node
    Node* new_head = this_node;
    if (list_node->data < this_node->data)
    {
      new_head = list_node;
      list_node = list_node->next;
    }
    else
    {
      this_node = this_node->next;
    }

    Node* new_list_node = new_head;

    while(NULL != new_list_node)
    {
      if ((NULL == list_node) && (NULL == this_node))
      {
        // do nothing
      }
      else if ((NULL == list_node) && (NULL != this_node))
      {
        new_list_node->next = this_node;
        this_node = this_node->next;
      }
      else if ((NULL == this_node) && (NULL != list_node))
      {
        new_list_node->next = list_node;
        list_node = list_node->next;
      }
      else if (list_node->data < this_node->data)
      {
        new_list_node->next = list_node;
        list_node = list_node->next;
      }
      else
      {
        new_list_node->next = this_node;
        this_node = this_node->next;
      }

      new_list_node = new_list_node->next;
    }

    this->head = new_head;
    list.head = NULL;
  }


  /// Reverse the list elements.
  /// Expect O(n) performance.
  void reverse(void)
  {
    if (2 > this->size())
    {
      return;
    }

    Node* new_head = NULL;
    Node* node = this->head;

    do
    {
      Node* const next_node = node->next;

      node->next = new_head;
      new_head = node;

      node = next_node;
    } while (node);

    this->head = new_head;
  }


  /// Returns true if linked list contains a cycle.
  /// Expect O(n) performance.
  bool is_cyclic(void) const
  {
    if (this->empty())
    {
      return false;
    }

    Node* n1 = this->head;

    if (1 == this->size())
    {
      return n1->next == n1;
    }

    Node* n2 = n1->next;

    while ((NULL != n2) && (NULL != n1))
    {
      if ((n1 == n2) || (n1 == n2->next))
      {
        return true;
      }

      n1 = n1->next;

      n2 = n2->next;
      if (n2)
      {
        n2 = n2->next;
      }
    }

    return false;
  }


  /// Test if this list is equivalent to other list.
  bool equivalent(const SingleLinkedList& other)
  {
    Node* this_node = this->head;
    Node* other_node = other.head;

    if (NULL == this_node)
    {
      return (NULL == other_node);
    }

    if (NULL == other_node)
    {
      return false;
    }

    do
    {
      if (!this_node->equivalent(*other_node))
      {
        return false;
      }

      this_node = this_node->next;
      other_node = other_node->next;
    } while ((NULL != this_node) && (NULL != other_node));

    return ( (NULL == this_node) && (NULL == other_node));
  }


  /// External stream function.
  template<class U>
  friend std::ostream& operator << ( std::ostream& stream
                                   , const SingleLinkedList<U>& list);


protected:

  /// The list node object.
  struct Node
  {
    Node(T value)
      : next(NULL), data(value)
    {
    }

    Node(T value, struct Node* next_node)
      : next(next_node), data(value)
    {
    }

    bool operator < (const Node& other) const
    {
      return this->data < other.data;
    }

    bool equivalent(const Node& other) const
    {
      return !( ((*this) < other) || (other < (*this)) );
    }

    struct Node* next;
    T data;
  };


  Node* begin(void) const
  {
    return this->head;
  }


  /// Method to swap adjacent node 0 and node 1.
  /// Since this is a single linked list,
  /// must also pass pointer to nodes that point to previous n0.
  void swap_adjacent(Node* n0_prev, Node*& n0, Node*& n1)
  {
    assert(n0);
    assert(n1);

    // swap the pointers
    Node* const n1_next = n1->next;
    n1->next = n0;
    n0->next = n1_next;

    if (NULL != n0_prev)
    {
      n0_prev->next = n1;
    }

    // swap the arguments
    Node* temp_n0 = n0;
    n0 = n1;
    n1 = temp_n0;
  }


  /// Perform a deep copy.
  /// Expect O(n) performance.
  SingleLinkedList& deep_copy(const SingleLinkedList& other)
  {
    if (this == &other)
    {
      return *this;
    }

    this->clear();

    if (other.empty())
    {
      return *this;
    }

    Node* other_node = other.head;

    // attach the head
    this->head = new Node(other_node->data);
    Node* this_node = this->head;

    other_node = other_node->next;
    while (other_node)
    {
      this_node->next = new Node(other_node->data);
      this_node = this_node->next;
      other_node = other_node->next;
    }

    return *this;
  }


private:

  /// The head of the list.
  Node* head;
};




/// Stream list data.
/// Data is output in C++ array initializer format
/// (i.e. comma-separated with curly braces)
template <typename T>
std::ostream& operator << (std::ostream& stream, const SingleLinkedList<T>& list) {

  typename SingleLinkedList<T>::Node* node = list.head;

  stream << "{ ";

  while(NULL != node)
  {
    stream << node->data;
    node = node->next;
    if (NULL != node)
    {
      stream << ", ";
    }
    else
    {
      stream << " ";
    }
  }

  stream << "}";

  return stream;
}




#endif//SINGLE_LINKED_LIST
