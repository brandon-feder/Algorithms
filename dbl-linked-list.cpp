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
            Node *aCurrent = getNode(a);
            Node *bCurrent = getNode(b);

            // If a is the index of the first node and b is not the last node
            if(false)
            {
            } else // Otherwise
            {

                Node *aPrev = getNode(a-1);
                Node *aNext = getNode(a+1);
                Node *bPrev = getNode(b-1);
                Node *bNext = getNode(b+1);

                if(b-a == 1)
                {
                    aCurrent->next = bNext;
                    bCurrent->next = aCurrent;
                    aCurrent->prev = bCurrent;
                    bCurrent->prev = aPrev;

                    if(aPrev != NULL)
                        aPrev->next = bCurrent;

                    if(bNext != NULL)
                        bNext->prev = aCurrent;

                    if(a == 0)
                        root = bCurrent;
                } else
                {
                //
                    aCurrent->next = bNext;
                    bCurrent->next = aNext;
                    aCurrent->prev = bPrev;
                    bCurrent->prev = aPrev;

                    if(aPrev != NULL)
                        aPrev->next = bCurrent;

                    bPrev->next = aCurrent;
                    aNext->prev = bCurrent;

                    if(bNext != NULL)
                        bNext->prev = aCurrent;

                    if(a == 0)
                        root = bCurrent;

                }
            }

        }

        Node *getNode(int index)
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

    public:
        // Returns the size of the new list
        void append(data_type v)
        {
            // Create the new node
            Node *newNode = new Node();
            newNode->value = v;

            if(size == 0) {
                root = newNode;
            } else {
                Node *currentNode = root;
                for(int i = 0; i < size-1; i++)
                {
                    currentNode = currentNode->next;
                }

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
            Node *currentNode = root;
            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

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

            Node* currentNode = root;

            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

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

            } else if(index == size-1) /// If removing the last element
            {
                // Find the second to last element and set set its next to NULL
                Node *currentNode = root;
                for(int i = 0; i < size-2; i++)
                {
                    currentNode = currentNode->next;
                }

                returnValue = currentNode->next->value;
                currentNode->next = NULL;

            } else // If removing any element other than the first or last
            {
                // Set the index-1 element to point to the index+1 element and vis versa
                Node *currentNode = root;

                for(int i = 0; i < index-1; i++)
                {
                    currentNode = currentNode->next;
                }

                returnValue = currentNode->next->value;
                currentNode->next->next->prev = currentNode;
                currentNode->next = currentNode->next->next;
            }

            --size;
            return returnValue;
        }


        // Implementation of bubble sort
        // Note* I could make this more efficient by making the swap function return the next node to swap instead of finding a and b from scratch everyime
        // But that takes away from the elegance of the solution and is pointless as bubble sort is not efficient in the first place which is why I did not
        // do that. Its just a pointer demonstration instead of a practical solution
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
                    data_type a = getNode(i)->value;
                    data_type b = getNode(i+1)->value;

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
