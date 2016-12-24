#include <emscripten/bind.h>
#include <string>
#include <vector>

class Todo {
    public:
        Todo(const std::string & task)
            : task_(task), isDone_(false)
        {}
        Todo(std::string && task)
            : task_(std::forward<std::string>(task)), isDone_(false)
        {}

        const std::string getTask() const {
            return task_;
        }
        const bool getIsDone () const {
            return isDone_;
        }

        void done() {
            isDone_ = true;
        }
        void unDone() {
            isDone_ = false;
        }
        void toggle() {
            isDone_ = !isDone_;
        }

    private:
        std::string task_;
        bool isDone_;
};

EMSCRIPTEN_BINDINGS(todo) {
    emscripten::class_<Todo>("Todo")
        .constructor<std::string>()
        .function("done", &Todo::done)
        .function("unDone", &Todo::unDone)
        .function("toggle", &Todo::toggle)
        .property("task", &Todo::getTask)
        .property("isDone", &Todo::getIsDone)
        ;
}
