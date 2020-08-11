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
            if(a == 0 && b-a > 1)
            {
                Node *aNext = getNode(a+1);
                Node *bPrev = getNode(b-1);
                Node *bNext = bPrev->next->next;

                bCurrent->next = aNext;
                root = bCurrent;
                aCurrent->next = bNext;
                bPrev->next = aCurrent;


            }
            else if(a == 0 && b-a == 1) // If the nodes are consecutive and the first node is the first of the list
            {
                Node *bNext = getNode(b+1);

                bCurrent->next = aCurrent;
                root = bCurrent;
                aCurrent->next = bNext;

            } else if(a != 0 && b-a == 1)
            {
                Node *aPrev = getNode(a-1);
                Node *bNext = getNode(b+1);

                aPrev->next = bCurrent;
                aCurrent->next = bNext;
                bCurrent->next = aCurrent;


            } else // Otherwise
            {
                Node *aPrev = getNode(a-1);
                Node *aNext = aPrev->next->next;
                Node *bPrev = getNode(b-1);
                Node *bNext = bPrev->next->next;

                aPrev->next = bCurrent;
                bPrev->next = aCurrent;
                aCurrent->next = bNext;
                bCurrent->next = aNext;
            }
        }

        // Get a pointer to the node at index index
        Node *getNode(int index)
        {
            Node *currentNode = root;

            for(int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            return currentNode;
        }

    public:
        // Returns the size of the new list
        int append(data_type v)
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
                Node *currentNode = root;
                for(int i = 0; i < size-1; i++)
                {
                    currentNode = currentNode->next;
                }

                // Assighn the last elements next variable to point to the next node
                currentNode->next = newNode;
            }

            size += 1; // Increment the size
            return size;
        }

        data_type get(int index)
        {
            if(index >= size || index < 0)
                std::cout << "Error: Invalid index in function get()\n";

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
                std::cout << "Error: Invalid index in function set()\n";

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

        int remove(int index)
        {
            if(index >= size || index < 0)
                std::cout << "Error: Invalid index in function remove()\n";

            if(index == 0) // If removing the first element
            {
                //Set the root to be the second element
                root = root->next;
            } else if(index == size-1) /// If removing the last element
            {
                // Find the second to last element and set set its next to NULL
                Node *currentNode = root;
                for(int i = 0; i < size-2; i++)
                {
                    currentNode = currentNode->next;
                }

                currentNode->next = NULL;

            } else // If removing any element other than the first or last
            {
                // Set the index-1 element to point to the index+1 element
                Node *currentNode = root;

                for(int i = 0; i < index-1; i++)
                {
                    currentNode = currentNode->next;
                }

                currentNode->next = currentNode->next->next;
            }

            --size;
            return size;
        }

        // Sorts the list of primatives from smallest to greatest using selection sort
        void sort()
        {
            if(size == 0)
                return;

            // The node so start the sort on each iteration
            Node *start = root;
            for(int i = 0; i < size-1; i++)
            {
                Node *currentNode = start->next; // The currentNode being compared
                Node *minNode = currentNode; // The min node found

                // Find the min
                for(int j = i+1; j < size; j++)
                {
                    if(currentNode->value < minNode->value)
                    {
                        minNode = currentNode;
                    }
                    currentNode = currentNode->next;
                }

                // Swap the start and the min
                data_type temp = start->value;
                start->value = minNode->value;
                minNode->value = temp;

                start = start->next; // Increment the element to start on
            }
        }


        // Implementation of bubble sort
        // Note* I could make this more efficient by making the swap function return the next node to swap instead of finding a and b from scratch everyime
        // But that takes away from the elegance of the solution and is pointless as bubble sort is not efficient in the first place which is why I did not
        // do that. Its just a pointer demonstration instead of a practical solution
        void bubbleSort()
        {
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
                        std::cout << i << " " << a << " " << b << "\n";
                        isDone = false;
                        swap(i, i+1);
                        std::cout << "Swapepd\n";


                    }
                }
            }
        }
};
