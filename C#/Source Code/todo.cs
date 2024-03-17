using System;
using System.Collections.Generic;

public class Task {
    public string Description { get; set; }
    public bool Completed { get; set; }
}

public class TodoList {
    private List<Task> tasks = new List<Task>();

    public void AddTask(string description) {
        Task newTask = new Task { Description = description, Completed = false };
        tasks.Add(newTask);
        Console.WriteLine("Task added successfully.");
    }

    public void MarkTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.Count) {
            tasks[index].Completed = true;
            Console.WriteLine("Task marked as completed.");
        } else {
            Console.WriteLine("Invalid task index.");
        }
    }

    public void DeleteTask(int index) {
        if (index >= 0 && index < tasks.Count) {
            tasks.RemoveAt(index);
            Console.WriteLine("Task deleted successfully.");
        } else {
            Console.WriteLine("Invalid task index.");
        }
    }

    public void DisplayTasks() {
        Console.WriteLine("Tasks:");
        for (int i = 0; i < tasks.Count; ++i) {
            Console.Write($"{i + 1}. ");
            if (tasks[i].Completed)
                Console.Write("[X] ");
            else
                Console.Write("[ ] ");
            Console.WriteLine(tasks[i].Description);
        }
    }
}

class Program {
    static void Main(string[] args) {
        TodoList todoList = new TodoList();
        int choice;
        string description;
        int index;

        do {
            Console.WriteLine("\n1. Add Task");
            Console.WriteLine("2. Mark Task as Completed");
            Console.WriteLine("3. Delete Task");
            Console.WriteLine("4. View Tasks");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice: ");
            choice = int.Parse(Console.ReadLine());

            switch (choice) {
                case 1:
                    Console.Write("Enter task description: ");
                    description = Console.ReadLine();
                    todoList.AddTask(description);
                    break;
                case 2:
                    Console.Write("Enter task index to mark as completed: ");
                    index = int.Parse(Console.ReadLine());
                    todoList.MarkTaskAsCompleted(index - 1);
                    break;
                case 3:
                    Console.Write("Enter task index to delete: ");
                    index = int.Parse(Console.ReadLine());
                    todoList.DeleteTask(index - 1);
                    break;
                case 4:
                    todoList.DisplayTasks();
                    break;
                case 5:
                    Console.WriteLine("Exiting...");
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        } while (choice != 5);
    }
}
