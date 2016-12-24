#include <emscripten/bind.h>
#include <string>
#include <vector>

class Todo {
    public:
        Todo(const std::string & title)
            : title_(title), isDone_(false)
        {}
        Todo(std::string && title)
            : title_(std::forward<std::string>(title)), isDone_(false)
        {}

        const std::string getTitle() const {
            return title_;
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
        std::string title_;
        bool isDone_;
};

EMSCRIPTEN_BINDINGS(todo) {
    emscripten::class_<Todo>("Todo")
        .constructor<std::string>()
        .function("done", &Todo::done)
        .function("unDone", &Todo::unDone)
        .function("toggle", &Todo::toggle)
        .property("title", &Todo::getTitle)
        .property("isDone", &Todo::getIsDone)
        ;
}
