using namespace std;

typedef size_t size_t;
template <typename T>
class stack {
private:

	struct node
	{
		T item;
		node* next;
		node(const T& item, node* next) :
			item(item),
			next(next) {}
		~node() {}
	};

	// Private remnants of it's prior linked list design
	// Made private so user doesn't have random access available 
	void insert(const T& item, const size_t& index)
	{
		node* current = head;
		if (head == NULL)
		{
			head = new node(item, NULL);
		}
		else if (index == 0)
		{
			head = new node(item, current);
		}
		else
		{
			for (int i = 0; i < (int)index - 1; i++)
			{
				if (current->next != NULL)
				{
					current = current->next;
				}
			}
			current->next = new node(item, current->next);
		}
	}
	// Private so the user doesn't mess everything up by changing the head.
	node* head = NULL;

public:
	//Constructor and deconstructor
	stack() {}
	~stack() {
		// remove all items
		while (head != NULL) {
			node* curr = head;
			head = head->next;
			delete curr;
		}
	}
	//returns whether of not the stack is empty or not
	bool is_empty() const
	{
		return (this->head == NULL);
	}
	//Returns the size of the stack 
	size_t size() const
	{
		node* current = head;
		size_t sum = 0;
		if (head == NULL)
		{
			return sum;
		}
		else
		{
			while (current->next != NULL)
			{
				sum++;
				current = current->next;
			}
			return sum + 1;
		}
	}
	//Adds item to the stack
	void push(const T& item)
	{
		node* current = head;
		if (is_empty())
		{
			insert(item, 0);
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new node(item, NULL);
		}
	}
	//Removes and returns the most recently added item
	T pop()
	{
		node* current = head;
		node* previous = NULL;
		if (is_empty())
		{
			cerr << "EMPTY_LIST_EXCEPTION: Linked List is empty. \n";
			return head->item;
		}
		else if (current->next == NULL)
		{
			T gone = current->item;
			head = NULL;
			delete current;
			return gone;
		}
		else
		{
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			previous->next = NULL;
			T gone = current->item;
			delete current;
			return gone;
		}
	}
};