#include <iostream>
#include <vec3.hpp>
#include <lineSegment.hpp>
int main()
{
    LineSegment l1(vec3f(1.0, 2.0, 2.0), vec3f(4.0, 3.0, 2.0));
    LineSegment l2(vec3f(1.0, 0.0, 1.0), vec3f(4.0, -6.0, -1.0));
    float d = LineSegment:: distanceBetweenLines(l1, l2);

    LineSegment nl = LineSegment::shortestLineSegment(l1, l2, 1);
    LineSegment n2 = LineSegment::shortestLineSegment(l1, l2, 0);

    std::cout << "COMPUTED DISTANCE IS::" << d << "\n" 
              << "DISTANCE WITH SHORTEST LINE SEGMENT MAGNITUDE::" << nl.segmentLength() << "\n" 
              << "DISTANCE LINE SEGMENT MAGNITUDE WITHIN SEGMENT LIMITS::" << n2.segmentLength() << "\n";

    return 0;
}


