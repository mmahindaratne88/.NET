#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added successfully.\n";
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task deleted successfully.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void displayTasks() {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string description;
    int index;

    do {
        cout << "\n1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Delete Task\n";
        cout << "4. View Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskAsCompleted(index - 1);
                break;
            case 3:
                cout << "Enter task index to delete: ";
                cin >> index;
                todoList.deleteTask(index - 1);
                break;
            case 4:
                todoList.displayTasks();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
