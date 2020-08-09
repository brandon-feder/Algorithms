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

        int getSize()
        {
            return size;
        }
};
