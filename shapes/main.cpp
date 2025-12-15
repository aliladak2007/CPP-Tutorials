#include "point.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "composite_shape.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A {
public:
    A() {
        cout << "A constructed\n";
    }
    ~A() {
        cout << "A destroyed\n";
    }
};

class B {
public:
    B() {
        cout << "B constructed\n";
    }
    ~B() {
        cout << "B destroyed\n";
    }
};

int main() {
    // --- Q1: basic scene with circles and a point query ---
    vector<shared_ptr<shape>> scene;

    for (int y = 0; y <= 10; y++) {
        scene.push_back(make_shared<circle>(point(0, y), 4));
    }

    point query(3, 5);

    cout << "Shapes that contain (3,5) before scaling:\n";
    for (const shared_ptr<shape>& p : scene) {
        if (p->contains(query)) {
            cout << "  " << p->description() << '\n';
        }
    }

    // --- Q2: test scale(double factor) on all shapes in the scene ---
    cout << "\nScaling all shapes in scene by factor 2...\n";
    for (shared_ptr<shape>& p : scene) {
        p->scale(2.0);
    }

    cout << "Shapes that contain (3,5) after scaling by 2:\n";
    for (const shared_ptr<shape>& p : scene) {
        if (p->contains(query)) {
            cout << "  " << p->description() << '\n';
        }
    }

    // --- Q3: test composite_shape behaviour ---
    cout << "\nTesting composite_shape:\n";

    auto c1 = make_shared<circle>(point(0, 0), 3);
    auto c2 = make_shared<circle>(point(4, 0), 3);
    auto comp = make_shared<composite_shape>(c1, c2);

    cout << "Composite before scaling: " << comp->description() << '\n';

    point q1(1, 0);
    point q2(5, 0);

    cout << "  Contains (1,0)? " << (comp->contains(q1) ? "yes" : "no") << '\n';
    cout << "  Contains (5,0)? " << (comp->contains(q2) ? "yes" : "no") << '\n';

    comp->scale(2.0);

    cout << "Composite after scaling by 2: " << comp->description() << '\n';
    cout << "  Contains (1,0)? " << (comp->contains(q1) ? "yes" : "no") << '\n';
    cout << "  Contains (5,0)? " << (comp->contains(q2) ? "yes" : "no") << '\n';

    return 0;
}
