#include <gtkmm.h>

class MyWindow : public Gtk::Window {
public:
    MyWindow(Gtk::Window &window) : Gtk::Window(window) {}

    virtual void on_destroy() {
        Gtk::main_quit();
    }
};

int main(int argc, char *argv[]) {
    Gtk::Main main;

    MyWindow window(Gtk::Window("My Window"));
    window.set_title("My Window");

    main.run(window);

    return 0;
}
