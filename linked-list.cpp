// Single direction, linear, linked list class
template <class data_type>

class LinkedList
{
    private:
        struct Node
        {
            Node *next  = NULL; // Contains the next node in the list
            data_type value; // The value contained by the current node
        };

        Node *root = NULL; // First element of the Linked List
        int size = 0; // The number of element in the list

        void swap(int a, int b)
        {
            // Pointers to the a and b nodes
            Node *aCurrent = getNodePointer(a);
            Node *bCurrent = getNodePointer(b);

            // Pointers to the nodes that point to a and b
            Node *aNext = getNodePointer(a+1);
            Node *aPrev = ( a == 0 ) ? root : getNodePointer(a-1);
            Node *bNext = getNodePointer(b+1);
            Node *bPrev = getNodePointer(b-1);

            (( a == 0 ) ? root : aPrev->next) = bCurrent;
            bPrev->next = aCurrent;
            aCurrent->next = bNext;
            bCurrent->next = ( b-a == 1 ) ? aCurrent : aNext;
        }

        // Get a pointer to the node at index index
        Node *getNodePointer(int index)
        {
            if(index < 0 || index >= size) { return NULL; }

            Node *currentNode = root;
            for(int i = 0; i < index; i++) { currentNode = currentNode->next; }

            return currentNode;
        }

    public:
        LinkedList() {}

        ~LinkedList()
        {
            // https://stackoverflow.com/questions/20297524/c-free-invalid-pointer
            // int *size_ptr = &size;
            // delete size_ptr;
        }

        // Returns the size of the new list
        void append(data_type v)
        {
            // Create the new node
            Node *newNode = new Node();
            newNode->value = v;

            if(size == 0) // If the linked list is empty
            {
                root = newNode; // Assighn newNode to the root
            } else  // If not empty
            {
                // Iterate through every element in the list
                Node *currentNode = getNodePointer(size-1);

                // Assighn the last elements next variable to point to the next node
                currentNode->next = newNode;
            }

            ++size; // Increment the size
        }

        // Appends the new element to the front of the list
        void append_front(data_type v)
        {
            // Create a new node
            Node *newNode = new Node();
            newNode->value = v;
            newNode->next = root; // Its next value will be the current first node
            root = newNode; // It is now the first node
            ++size; // Increment size
        }

        data_type get(int index)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function get()\n";
                exit(0);
            }

            Node *currentNode = getNodePointer(index);
            return currentNode->value; // return the value of that list node
        }

        void set(int index, data_type val)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function set()\n";
                exit(0);
            }

            Node* currentNode = getNodePointer(index);

            currentNode->value = val;
        }

        int getSize()
        {
            return size;
        }

        data_type remove(int index)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function remove()\n";
                exit(0);
            }

            data_type returnValue;
            if(index == 0) // If removing the first element
            {
                //Set the root to be the second element
                returnValue = root->value;
                root = root->next;
            } else /// If removing the last element
            {
                // Find the second to last element and set set its next to NULL
                Node *currentNode = (index == size-1) ? getNodePointer(size-2) : getNodePointer(index-1);

                returnValue = currentNode->next->value;
                currentNode->next = (index == size-1) ? NULL : currentNode->next->next;
            }

            --size;
            return returnValue;
        }

        // Implementation of bubble sort
        void bubbleSort()
        {
            // Note* There are many more codes that can be added, but these are the main ones
            std::string dName =  std::string(typeid(data_type).name());
            if(! (dName == "11UnicodeChar" || dName == "c" || dName == "i" || dName == "f" || dName == "d") )
            {
                std::cout << "Error: Invalid type to sort\n";
                exit(0);
            }

            if(size == 0)
                return;

            bool isDone = false; // Whether all the nodes are sorted
            while(!isDone)
            {
                isDone = true;

                // For every pair of nodes
                for(int i = 0; i < size-1; i++)
                {
                    data_type a = getNodePointer(i)->value;
                    data_type b = getNodePointer(i+1)->value;

                    // If the first of the pair is < than the second, swap
                    if(a > b)
                    {
                        isDone = false;
                        swap(i, i+1);
                    }
                }
            }
        }
};
