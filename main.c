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

int free_mem(LinkedNode **head);

int print_nodes(LinkedNode *head);

// ====================== MAIN =========================

int main()
{
        LinkedNode *head = NULL;
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
                log("LinkedNode is empty");
                return 0;
        }

        LinkedNode *currentNode = head;

        while (currentNode != NULL)
        {
                int id = currentNode->rowNum;
                char *data = currentNode->data;

                printf("Order: %d\n\t\t%s\n", id, data);
                currentNode = currentNode->next;
        }
        return 1;
}

// ==============================================================
int remove_node(LinkedNode **head, int value)
{
        // TODO
        return 1;
}

// ==============================================================

int add_node(LinkedNode **head, char *value)
{
        LinkedNode *new_node = create_node(value);

        if (new_node == NULL)
        {
                log("[!] Failed add_node\n new node is NULL");
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
                log("[+] Success create_node\n new node created successfuly");
                node->rowNum = ++counter;
                node->data = value;
        }
        return node;
}
