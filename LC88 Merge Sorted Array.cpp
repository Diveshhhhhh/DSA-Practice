#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Define Task Structure
struct Task {
    int id;
    string description;
    string priority;
    bool completed;
};

// Function Prototypes
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void completeTask(vector<Task> &tasks);
void saveTasksToFile(const vector<Task> &tasks);
void loadTasksFromFile(vector<Task> &tasks);
void menu();

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);
    
    int choice;
    do {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: completeTask(tasks); break;
            case 4: saveTasksToFile(tasks); cout << "Tasks saved. Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

// Function Definitions
void menu() {
    cout << "\n===== TO-DO LIST =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Save & Exit\n";
}

void addTask(vector<Task> &tasks) {
    Task newTask;
    newTask.id = tasks.size() + 1;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    cout << "Enter priority (High/Medium/Low): ";
    cin >> newTask.priority;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    for (const auto &task : tasks) {
        cout << task.id << ". " << task.description << " [" 
             << task.priority << "] - " 
             << (task.completed ? "Completed" : "Pending") << endl;
    }
}

void completeTask(vector<Task> &tasks) {
    int id;
    cout << "Enter Task ID to mark as completed: ";
    cin >> id;
    if (id > 0 && id <= tasks.size()) {
        tasks[id - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid Task ID!\n";
    }
}

void saveTasksToFile(const vector<Task> &tasks) {
    ofstream file("tasks.txt");
    for (const auto &task : tasks) {
        file << task.id << "," << task.description << "," 
             << task.priority << "," << task.completed << endl;
    }
    file.close();
}

void loadTasksFromFile(vector<Task> &tasks) {
    ifstream file("tasks.txt");
    Task task;
    while (file >> task.id) {
        file.ignore();
        getline(file, task.description, ',');
        file >> task.priority >> task.completed;
        tasks.push_back(task);
    }
    file.close();
}
