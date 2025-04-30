#include <stdio.h>
#include <stdlib.h>

// ======================= MACRO =======================

#define log(message) printf("%s\n", message)

// ======================= STATIC ======================

static int counter = 0;

// ======================= STRUCT ======================

typedef struct LinkedNode
{
        int rowNum;
        char *data;
        struct LinkedNode *next;

} LinkedNode;

// ====================== PROTOTYPE ====================

int add_node(LinkedNode **head, char *value);

LinkedNode *create_node(char *value);

int remove_node(LinkedNode **head, int id);

int print_nodes(LinkedNode *head);

// ====================== MAIN =========================

int main()
{
        LinkedNode *head = NULL;
        add_node(&head, "this is a test text");
        add_node(&head, "this is a test text");
        add_node(&head, "this is a test text");

        remove_node(&head, 2);
        add_node(&head, "this is a test text");
        add_node(&head, "this is a test text");
        remove_node(&head, 5);
        add_node(&head, "this is a test text");
        add_node(&head, "this is a test text");

        print_nodes(head);
        return 0;
}

// ==============================================================

int print_nodes(LinkedNode *head)
{
        if (head->rowNum == 0)
        {
                log("[+] LinkedNode is empty");
                return 0;
        }

        LinkedNode *currentNode = head;

        while (currentNode != NULL)
        {
                int id = currentNode->rowNum;
                char *data = currentNode->data;

                printf("id: %d\n\t%s\n\n", id, data);
                currentNode = currentNode->next;
        }
        return 1;
}

// ==============================================================

int remove_node(LinkedNode **head, int row)
{

        if (*head == NULL)
        {
                return 0;
        }

        LinkedNode *currentNode = *head;

        if (currentNode->rowNum == row)
        {
                *head = currentNode->next;
                free(currentNode);
                return 1;
        }

        while (currentNode->next != NULL)
        {
                LinkedNode *nextNode = currentNode->next;

                if (nextNode->rowNum == row)
                {
                        currentNode->next = nextNode->next;
                        free(nextNode);
                        log("[+] Success remove_node");
                        return 1;
                }

                currentNode = currentNode->next;
        }
        return 0;
}

// ==============================================================

int add_node(LinkedNode **head, char *value)
{
        LinkedNode *new_node = create_node(value);

        if (new_node == NULL)
        {
                log("[-] Failed add_node");
                perror("new node is NULL");
                return 0;
        }

        new_node->next = *head;
        *head = new_node;
        return 1;
}

// ==============================================================

LinkedNode *create_node(char *value)
{
        LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));

        if (node != NULL)
        {
                log("[+] Success create_node");
                node->rowNum = ++counter;
                node->data = value;
        }
        return node;
}
