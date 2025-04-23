#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

//Array for storing rescue log
char* rescueLog[6];
int logCount = 0;

// Singly Linked List for damaged robots
typedef struct Node {
    char* name;
    struct Node* next;
} Node;

Node* damagedHead = NULL;

// Doubly Linked List for repaired robots
typedef struct DNode {
    char* name;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* repairedHead = NULL;
DNode* repairedTail = NULL;

// Circular Linked List for priority redeployment
typedef struct CNode {
    char* name;
    struct CNode* next;
} CNode;

CNode* circularHead = NULL;

// Stack for urgent tasks
char* stack[MAX];
int top = -1;

// Queue for mission requests
char* queue[MAX];
int front = -1, rear = -1;

void addDamagedRobot(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->next = damagedHead;
    damagedHead = newNode;
}

void removeDamagedRobot(char* name) {
    Node *curr = damagedHead, *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) damagedHead = curr->next;
            else prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void addRepairedRobot(char* name) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->name = name;
    newNode->prev = repairedTail;
    newNode->next = NULL;
    if (repairedTail) repairedTail->next = newNode;
    else repairedHead = newNode;
    repairedTail = newNode;
}

void traverseForward() {
    DNode* curr = repairedHead;
    printf("Forward traversal:\n");
    while (curr) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

void traverseBackward() {
    DNode* curr = repairedTail;
    printf("Backward traversal:\n");
    while (curr) {
        printf("%s\n", curr->name);
        curr = curr->prev;
    }
}

void addToCircularList(char* name) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->name = name;
    if (!circularHead) {
        circularHead = newNode;
        newNode->next = circularHead;
    } else {
        CNode* temp = circularHead;
        while (temp->next != circularHead) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = circularHead;
    }
}

void traverseCircularList(int rounds, int n) {
    printf("Circular traversal (%d rounds):\n", rounds);
    if (!circularHead) return;

    CNode* curr = circularHead;
    for (int i = 0; i < rounds * n; i++) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

void push(char* task) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = task;
}

char* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}

void enqueue(char* task) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = task;
}

char* dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue[front++];
}

void simulateMissionAndUrgency() {
    printf("=== a) Mission and Urgency ===\n");
    int n, u;
    printf("Enter number of tasks (Atleast 5) ");
    scanf("%d", &n);
    getchar();
    char* tasks[n];
    printf("Available tasks \n1.Scanner\n2.Digger\n3.Lift\n4.Light\n5.Drone\n");
    for (int i = 0; i < n; i++)
    {
        tasks[i] = (char *)malloc(sizeof(char)*10);
        gets(tasks[i]);
    }
    printf("\n1-Urgent, 0-Not Urgent\n");
    scanf("%d", &u);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", tasks[i]);
    }

    for (int i = 0; i < MAX; i++)
        enqueue(tasks[i]);

    if (u == 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            printf("%s\n", dequeue());
        }
    } else {
        for (int i = 0; i < MAX; i++)
            push(dequeue());

        printf("Urgent task handling order (LIFO):\n");
        for (int i = 0; i < MAX; i++)
            printf("%s\n", pop());
    }


    //printf("\nBonus: LIFO is ideal here because the most recent critical need (e.g., 'Cutter' to clear debris) must be addressed immediately for efficient rescue.\n");
}

void logMission(char* mission) {
    if (logCount < 6) {
        rescueLog[logCount++] = mission;
    } else {
        printf("Reporting oldest mission: %s\n", rescueLog[0]);
        for (int i = 1; i < 6; i++) {
            rescueLog[i - 1] = rescueLog[i];
        }
        rescueLog[5] = mission;
    }
}

void simulateRescueLogUnit() {
    printf("\n=== b) Rescue Log Unit ===\n");
    int n;
    printf("Enter number of Missions ");
    scanf("%d", &n);
    getchar();
    char* missions[n];
 
    for (int i = 0; i < n; i++)
    {
        missions[i] = (char *)malloc(sizeof(char)*50);
        gets(missions[i]);
        if (i > 5)
        {
            printf("\n%s is archived\n", missions[i-6]);
        }
    }

    for (int i = 0; i < n; i++) {
        logMission(missions[i]);
    }

    printf("Final Rescue Log:\n");
    for (int i = 0; i < 6; i++)
        printf("%s\n", rescueLog[i]);

    //printf("\nBonus: Logging and reporting helps update the control center and families about survivor progress and mission timelines.\n");
}

void simulateDamagedRobotTracker() {
    printf("\n=== c) Damaged Robot Tracker ===\n");
    int n;
    printf("Enter number of robots Damaged ");
    scanf("%d", &n);
    getchar();
    char* DRobots[n];
    for (int i = 0; i < n; i++)
    {
        DRobots[i] = (char*)malloc(sizeof(char)*10);
        gets(DRobots[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%s-Added to singly linked list\n", DRobots[i]);
        addDamagedRobot(DRobots[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n%s Removed from singly linked list and aadded to doubly linked list\n", DRobots[i]);
        removeDamagedRobot(DRobots[i]);
        addRepairedRobot(DRobots[i]);
    }


    traverseForward();
    traverseBackward();

   // printf("\nBonus: 'Digger' suffered a crushed arm under rubble. Technicians 3D-printed a reinforced replacement to get it back into action.\n");
}

void simulatePriorityRedeployment() {
    printf("\n=== d) Priority Redeployment ===\n");
    int n;
    printf("Enter number of Robots on Priority Deployment ");
    scanf("%d", &n);
    getchar();
    char* RRobots[n];
    for (int i = 0; i < n; i++)
    {
        RRobots[i] = (char*)malloc(sizeof(char)*10);
        gets(RRobots[i]);
    }

    for (int i = 0; i < n; i++)
    {
        addToCircularList(RRobots[i]);
    }

    traverseCircularList(2, n);

    //printf("\nBonus: 'Lift' is now equipped with a thermal camera to quickly locate survivors even through thick dust and darkness.\n");
}


int main()
{
    simulateMissionAndUrgency();
    simulateRescueLogUnit();
    simulateDamagedRobotTracker();
    simulatePriorityRedeployment();
    return 0;
}