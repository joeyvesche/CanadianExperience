/**
 * @file HeadTop.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_HEADTOP_H
#define CANADIANEXPERIENCE_HEADTOP_H

#include "ImageDrawable.h"

class HeadTop : public ImageDrawable{
private:
    /// Location of eye 1
    wxPoint mEye1 = wxPoint(40.0f, 80.0f);
    /// Location of eye 2
    wxPoint mEye2 = wxPoint(70.0f, 80.0f);

    /// Location of eyebrow part 1 start
    wxPoint mEyebrowStart1 = wxPoint(65.0f, 60.0f);
    /// Location of eyebrow part 1 end
    wxPoint mEyebrowEnd1 = wxPoint(80.0f, 63.0f);

    /// Location of eyebrow part 2 start
    wxPoint mEyebrowStart2 = wxPoint(30.0f, 63.0f);
    /// Location of eyebrow part 2 end
    wxPoint mEyebrowEnd2 = wxPoint(45.0f, 60.0f);

    /// Eyebrow offset
    wxPoint mOffsetEyebrow = wxPoint(0.0f, 0.0f);

public:
    /** Default constructor disabled */
    HeadTop() = delete;
    /** Copy constructor disabled */
    HeadTop(const HeadTop&) = delete;
    /** Assignment operator disabled */
    void operator=(const HeadTop&) = delete;

    HeadTop(const std::wstring& name, const std::wstring& filename);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    wxPoint TransformPoint(wxPoint p);

    /** Get if it is moveable
     * @return true unless overwritten
     */
     virtual bool IsMovable() { return true; }

     void DrawEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point);
     void DrawEyebrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint point1, wxPoint point2);

     /** Set the eye location of eye1
      * @param pos The new eye1 location
      */
      void SetEye1(wxPoint pos) { mEye1 = pos; }

      /** Set the eye location of eye2
       * @param pos The new eye2 location*/
       void SetEye2(wxPoint pos) { mEye2 = pos; }

      /** Get the location of eye2
      * @returns eye2 pos*/
      wxPoint GetEye2() const { return mEye2; }

      /** Set the eye location of Eyebrowstart1
      * @param pos The new Eyebrowstart1 location*/
      void SetEyebrowStart1(wxPoint pos) { mEyebrowStart1 = pos; }

      /** Set the eye location of EyebrowStart2
      * @param pos The new eye2 location*/
      void SetEyebrowStart2(wxPoint pos) { mEyebrowStart2 = pos; }

      /** Set the eye location of EyebrowEnd1
      * @param pos The new EyebrowEnd1 location*/
      void SetEyebrowEnd1(wxPoint pos) { mEyebrowEnd1 = pos; }

      /** Set the eye location of EyebrowEnd2
      * @param pos The new EyebrowEnd2 location*/
      void SetEyebrowEnd2(wxPoint pos) { mEyebrowEnd2 = pos; }

      /** Set the eyebrow offset if needed
      * @param pos The new Eyebrow offset*/
      void SetEyebrowOffset(wxPoint pos) { mOffsetEyebrow = pos; }

      void SetKeyframe();
};

#endif //CANADIANEXPERIENCE_HEADTOP_H
