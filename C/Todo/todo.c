#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    int completed;
};

struct TodoList {
    struct Task *tasks;
    int size;
    int capacity;
};

void initTodoList(struct TodoList *todoList) {
    todoList->tasks = (struct Task *)malloc(10 * sizeof(struct Task));
    todoList->size = 0;
    todoList->capacity = 10;
}

void addTask(struct TodoList *todoList, const char *description) {
    if (todoList->size == todoList->capacity) {
        todoList->capacity *= 2;
        todoList->tasks = (struct Task *)realloc(todoList->tasks, todoList->capacity * sizeof(struct Task));
    }
    struct Task newTask;
    strcpy(newTask.description, description);
    newTask.completed = 0;
    todoList->tasks[todoList->size++] = newTask;
    printf("Task added successfully.\n");
}

void markTaskAsCompleted(struct TodoList *todoList, int index) {
    if (index >= 0 && index < todoList->size) {
        todoList->tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void deleteTask(struct TodoList *todoList, int index) {
    if (index >= 0 && index < todoList->size) {
        for (int i = index; i < todoList->size - 1; ++i) {
            todoList->tasks[i] = todoList->tasks[i + 1];
        }
        todoList->size--;
        printf("Task deleted successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void displayTasks(struct TodoList *todoList) {
    printf("Tasks:\n");
    for (int i = 0; i < todoList->size; ++i) {
        printf("%d. ", i + 1);
        if (todoList->tasks[i].completed)
            printf("[X] ");
        else
            printf("[ ] ");
        printf("%s\n", todoList->tasks[i].description);
    }
}

void destroyTodoList(struct TodoList *todoList) {
    free(todoList->tasks);
}

int main() {
    struct TodoList todoList;
    int choice;
    char description[100];
    int index;

    initTodoList(&todoList);

    do {
        printf("\n1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. Delete Task\n");
        printf("4. View Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                getchar(); // Clear newline from input buffer
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove trailing newline
                addTask(&todoList, description);
                break;
            case 2:
                printf("Enter task index to mark as completed: ");
                scanf("%d", &index);
                markTaskAsCompleted(&todoList, index - 1);
                break;
            case 3:
                printf("Enter task index to delete: ");
                scanf("%d", &index);
                deleteTask(&todoList, index - 1);
                break;
            case 4:
                displayTasks(&todoList);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    destroyTodoList(&todoList);

    return 0;
}
