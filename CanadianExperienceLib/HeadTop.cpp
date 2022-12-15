/**
 * @file HeadTop.cpp
 * @author joeyv
 */

#include "pch.h"
#include "HeadTop.h"

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** Constructor
* @param name The drawable name
* @param filename The filename for the image */
HeadTop::HeadTop(const std::wstring& name, const std::wstring& filename) : ImageDrawable(name, filename)
{
}

/**
* Draw the image drawable
 * @param graphics Graphics context to draw on
*/
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);

    DrawEye(graphics, mEye1);

    DrawEye(graphics, mEye2);

    DrawEyebrow(graphics, mEyebrowStart1 - mOffsetEyebrow, mEyebrowEnd1 - mOffsetEyebrow);

    DrawEyebrow(graphics, mEyebrowStart2 - mOffsetEyebrow, mEyebrowEnd2 - mOffsetEyebrow);
}

/**
 * Draw the image drawable
 * @param graphics Graphics context to draw on
 * @param point Point we will draw at
 */
void HeadTop::DrawEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point)
{
    float wid = 15.0f;
    float hit = 20.0f;

    graphics->PushState();
    wxPoint p = TransformPoint(point);
    graphics->Translate(p.x, p.y);
    graphics->Rotate((float)(-mPlacedR * RtoD));
    wxBrush brush(*wxBLACK);
    graphics->SetBrush(brush);
    graphics->DrawEllipse(-wid / 2, -hit / 2, wid, hit);
    graphics->PopState();

}

/**
* Draw the image drawable
 * @param graphics Graphics context to draw on
 * @param point1 Point1 we will draw at
 * @param point2 Point2 we will end at
*/
void HeadTop::DrawEyebrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point1, wxPoint point2)
{
    wxPoint p1 = TransformPoint(wxPoint(point1.x, point1.y));
    wxPoint p2 = TransformPoint(wxPoint(point2.x, point2.y));

    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);
    graphics->StrokeLine(p1.x, p1.y, p2.x, p2.y);
}

/**
* Tranform a point from a location on the bitmap to a
 * location on the screen
 * @param p Point to transform
 * @return Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}


