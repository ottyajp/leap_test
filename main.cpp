#include <iostream>
#include <Leap.h>

using namespace std;

class SampleListener : public Leap::Listener{
public:
    void onInit(const Leap::Controller& controller){
        cout<<__FUNCTION__<<endl;
    }

    void onConnect(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onDisconnect(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onExit(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onFocusGained(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onFocusLost(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onServiceConnect(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onServiceDisconnect(const Leap::Controller&){
        cout<<__FUNCTION__<<endl;
    }

    void onDeviceChange(const Leap::Controller& controller){
        cout<<__FUNCTION__<<endl;
    }

    void onFrame(const Leap::Controller& controller){
//        auto frame = controller.frame();
        if(controller.frame().fingers().count()!=0){
            if(controller.frame().fingers().extended().count() == 0){
                cout<<" Rock    \r"<<flush;
            }
            if(controller.frame().fingers().extended().count() == 2){
                bool f1=false; bool f2=false;
                auto fi1 = controller.frame().fingers().extended()[0];
                auto fi2 = controller.frame().fingers().extended()[1];
                if(fi1.type()==1 || fi2.type()==1){
                    f1=true;
                }
                if(fi1.type()==2 || fi2.type()==2){
                    f2=true;
                }
                if(f2==true && f1==true){
                    cout<<" Scissors\r"<<flush;
                }
            }
            if(controller.frame().fingers().extended().count() == 5){
                cout<<" Paper   \r"<<flush;
            }
        }
    }
};

int main()
{
    SampleListener listener;
    Leap::Controller leap;
    leap.addListener(listener);

    cin.get();
    leap.removeListener(listener);
    return 0;
}
