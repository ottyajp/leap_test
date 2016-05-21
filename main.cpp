#include <iostream>
#include <Leap.h>

using namespace std;

class SampleListener : public Leap::Listener{
public:
    void onInit(const Leap::Controller& controller){
        cout<<__FUNCTION__<<endl;
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
