#ifndef LINESEG_HPP
#define LINESEG_HPP
#include <vec3.hpp>
#include <algorithm>
//
//This class reprsents line segment in parametric vector form: A + Bt, where A - origin vector, B - destination vector, t - scalar. Changing t moves destination along B vector.
//So, if t = [0;1], this form will represent line segment from A to B
//
typedef Vec3<float> vec3f;
class LineSegment
{
    public:
    //Line is defined by origin and destination, so there must be one
    LineSegment(const vec3f &origv, const vec3f &destv): orig(origv), dest(destv) {}
    //---Getters and setters---
    void setOrig(const vec3f &vector){orig = vector;}
    void setDest(const vec3f &vector){dest = vector;}


    vec3f getOrig(){return orig;}
    vec3f getDest(){return dest;}

    //---Math methods---
    float segmentLength(){return vec3f::getDistance(orig, dest);}
    float segmentLength() const {return vec3f::getDistance(orig, dest);}

    //Static method to check if 2 lines are parallel (|cross(u,v)| very close to 0)
    static bool isPrarllel(const LineSegment& l1, const LineSegment& l2)
    {
        float prarllelCheck = vec3f::cross(l1.dest, l2.dest).magnitude();
        return prarllelCheck <  0.0000001 && prarllelCheck > -0.0000001;
    }

    //Static method to calculate distance between line segments using this formula https://mathworld.wolfram.com/Line-LineDistance.html
    //D = |c.(a x b)|/|a x b|
    //this method is mostly for fast error checking
    static float distanceBetweenLines(const LineSegment &l1, const LineSegment &l2)
    {
        vec3f axb = vec3f::cross(l1.dest, l2.dest);
        vec3f c = l2.orig - l1.orig;
        float mag1 = abs(vec3f::dot(c, axb));
        float mag2 = axb.magnitude();
        return mag1/mag2;
    }

    //Algirthm to find nearest points on lines is from this paper, page 2: https://www.crewes.org/Documents/ResearchReports/2010/CRR201032.pdf
    //Last parameter allows to check distance between lines, not segments of them
    static LineSegment shortestLineSegment(const LineSegment &l1, const LineSegment &l2, bool checkWholeLines)
    {

        //if vectors are parallel, method mentioned above cannot be used
        if(isPrarllel(l1, l2))
        {
            std::cout << "CHECK CHECK \n";
            //find closest point on l1 to l2 origin, return line between those 2
            vec3f p21 = l2.orig - l1.orig;
            vec3f origToDest = l1.dest - l1.orig;
            //dot(v,v) = squared magnitude
            float otd2 = vec3f::dot(origToDest, origToDest);
            float otdDotP21 = vec3f::dot(p21, origToDest);
            //normilized "distance" from origin to closest poiint
            float t = otdDotP21 / otd2;
            //if lines are parallel, no need to clamp
            vec3f closestPoint(l1.orig + origToDest*t);

            return LineSegment(l2.orig, closestPoint);
        }

        vec3f p21 = l2.orig - l1.orig;
        vec3f M = vec3f::cross(l2.dest, l1.dest);
        float m2 = vec3f::dot(M,M);
        vec3f R = vec3f::cross(p21, M/m2);

        //scalar represinting nearest points on the lines in parametric form
        float t1 = vec3f::dot(R, l2.dest);
        float t2 = vec3f::dot(R, l1.dest);
        
        //segment distance 
        if (!checkWholeLines)
        {
            //found scalars can be out of range [0;1]
            t1 = std::clamp(t1, 0.f, 1.f);
            t2 = std::clamp(t2, 0.f, 1.f);
        }

        //vec3s are representing nearest points on line segments
        vec3f qOrig(l1.orig + l1.dest*t1);
        vec3f qDest(l2.orig + l2.dest*t2);

        return LineSegment(qOrig,qDest);
    }

    private:
        vec3f orig;
        vec3f dest;
};



#endif  