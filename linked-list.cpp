// Single direction, linear, linked list class
template <class data_type>

class LinkedList
{
    private:
        class Node
        {
            public:
                Node *next; // Contains the next node in the list
                data_type value; // The value contained by the current node

                Node()
                {
                    next = NULL; // NULL because initialy, there are no next nodes
                }

                // Recursevly check until the end of the list is found, then add the new element
                void append(data_type v)
                {
                    if(next == NULL)  // If is the last node
                    {

                        // Create the new node
                        Node *newItem = (Node *)malloc(sizeof(struct Node));;
                        newItem->value = v;

                        // Assighn it to be the next node of the current node
                        next = newItem;
                    } else  // If not the last node
                    {
                        next->append(v); // Do the same thing again to the next node
                    }
                }

                // Get the value of a node given its index
                data_type get(int depth)
                {
                    if(depth == 0)  // If at the correct node
                    {
                        return value; // return its value
                    } else  // Otherwise, recursevly do the same thing again to the next node
                    {
                        return next->get(depth-1);
                    }
                }
        };

        Node *root; // First element of the Linked List
        int size; // The number of element in the list

    public:
        LinkedList()
        {
            size = 0;
            root = NULL;
        }

        // Returns the size of the new list
        int append(data_type v)
        {
            if(root == NULL) // If no root exists yet (Size is 0)
            {

                // Create the new first node
                Node *newItem = (Node *)malloc(sizeof(struct Node));
                newItem->value = v;

                // Assighn the node to the root of the list
                root = newItem;
            } else // Otherwise if there are more than 0 nodes
            {
                // Recursevly append to the last node
                root->append(v);
            }

            size += 1; // Increment the size
            return size;
        }

        // Recursevly finds the value at the index given
        data_type get(int index)
        {
            return root->get(index);
        }

        int getSize() {
            return size;
        }
};
