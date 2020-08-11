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

        void swap(int a, int b)
        {
            int a_val = this->get(a);
            int temp = a_val;
            int b_val = this->get(b);

            this->set(a, b_val);
            this->set(b, temp);
        }

        // Sorts the list of primatives from smallest to greatest using selection sort
        void sort()
        {

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
};
