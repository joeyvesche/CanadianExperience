/**
 * @file PolyDrawable.cpp
 * @author joeyv
 */

#include "pch.h"
#include "PolyDrawable.h"
#include <vector>

using namespace std;

/** Destructor */
PolyDrawable::~PolyDrawable()
{

}

/**
 * Constructor
 * @param name The drawable name
 */
PolyDrawable::PolyDrawable(const std::wstring &name) : Drawable(name)
{
}

/** Draw this poly
* @param graphics The Graphics object we are drawing on */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!mPoints.empty()) {

        mPath = graphics->CreatePath();
        mPath.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition); // RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
        for (auto i = 1; i<mPoints.size(); i++)
        {
            mPath.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition); // RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);
        }
        mPath.CloseSubpath();

        wxBrush brush(mColor);
        graphics->SetBrush(brush);
        graphics->FillPath(mPath);
    }

}

/**
* Test to see if a mouse click is on this actor.
* @param pos Mouse position on drawing
* @return A drawable object we clicked on or nullptr if we missed.
*/
bool PolyDrawable::HitTest(wxPoint pos)
{
    return mPath.Contains(pos.x, pos.y);
}

/**
* Add a point to the current polly
 * @param point The point we are adding to the vector
*/
void PolyDrawable::AddPoint(wxPoint point)
{
    mPoints.push_back(point);
}