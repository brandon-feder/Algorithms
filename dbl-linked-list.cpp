template <class data_type>

class DblLinkedList
{
    private:
        struct Node
        {
            Node *next  = NULL; // Contains the next node in the list
            Node *prev  = NULL; // Contains the next node in the list
            data_type value; // The value contained by the current node
        };

        Node *root = NULL; // First element of the Linked List
        int size = 0; // The number of element in the list

        Node *getNodePointer(int index)
        {
            if(index < 0 || index >= size) {
                return NULL;
            }

            Node *currentNode = root;

            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            return currentNode;
        }

        void swap(int a, int b)
        {
            // Make sure a is the lesser index
            if(a > b)
            {
                int temp = b;
                b = a;
                a = temp;
            }

            // Pointers to the a and b nodes
            Node *aCurrent = getNodePointer(a);
            Node *bCurrent = getNodePointer(b);

            // A & B next and prev nodes
            Node *aPrev = getNodePointer(a-1);
            Node *aNext = getNodePointer(a+1);
            Node *bPrev = getNodePointer(b-1);
            Node *bNext = getNodePointer(b+1);

            aCurrent->next = bNext;
            bCurrent->next = (b-a == 1) ? aCurrent : aNext;
            aCurrent->prev = (b-a == 1) ? bCurrent : bPrev;
            bCurrent->prev = aPrev;


            if(aPrev != NULL)
                aPrev->next = bCurrent;

            if(bNext != NULL)
                bNext->prev = aCurrent;

            if(a == 0)
                root = bCurrent;
        }

    public:
        // DblLinkedList() {}
        // ~DblLinkedList() {
        //     delete root;
        //     delete data_type;
        //     delete size;
        // }
        // Returns the size of the new list
        void append(data_type v)
        {
            // Create the new node
            Node *newNode = new Node();
            newNode->value = v;

            if(size == 0) {
                root = newNode;
            } else {
                Node *currentNode = getNodePointer(size-1);

                // Assighn the last elements next variable to point to the next node and to the last node
                newNode->prev = currentNode;
                currentNode->next = newNode;
            }

            ++size; // Increment the size
        }

        // Appends the new element to the front of the list
        void append_front(data_type v)
        {
            Node *newNode = new Node();
            newNode->value = v;
            newNode->next = root;
            root = newNode;

            // Increment size
            ++size;

        }

        data_type get(int index)
        {
            if(index >= size || index < 0)
            {
                std::cout << "Error: Invalid index in function get()\n";
                exit(0);
            }

            // Iterate over the list until index index
            Node *currentNode = getNodePointer(index);

            // return the value of that list node
            return currentNode->value;
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
                returnValue =  root->value;
                root = root->next;
                root->prev = NULL;

            } else /// If removing the last element
            {
                // Find the second to last element and set set its next to NULL
                Node *currentNode = (index == size-1) ? getNodePointer(size-2) : getNodePointer(index-1);

                returnValue = currentNode->next->value;
                currentNode->next = (index == size-1) ? NULL : currentNode->next->next;

                if(index != size-1)
                    currentNode->next->next->prev = currentNode;
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

        void mergeSort() {
            
        }
};
