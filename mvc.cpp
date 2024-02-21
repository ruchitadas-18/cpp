#include <iostream>

//Model
class counterModel{
    private:
    int count;
    public:
    counterModel(): count(0){};

    constexpr int getCount() const{
        return count;
    }

    void inc(){
        count++;
    }

};

//View
class counterView{
    public:
    void display(int count) const{
        std::cout<<"Coueter: "<<count<<std::endl;
    }
};

//Controller
class counterController{
    private:
    counterModel& model;
    counterView& view;

    public:
    counterController (counterModel& model, counterView& view) : model(model), view(view){}

    void inc(){
        model.inc();
    }

    void displayChange(){
        inc();
        updateView();
    }
    void updateView() const{
        view.display(model.getCount());
    }
};


int main(int args, const char* argv[]){
    std::cout<<"MVC framework"<<std::endl;
    counterModel model;
    counterView view;
    counterController controller(model, view);

    //Intial display
    controller.displayChange();
    controller.displayChange();
    controller.displayChange();
    return 0;
}