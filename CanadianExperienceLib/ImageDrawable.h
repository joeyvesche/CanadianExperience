/**
 * @file ImageDrawable.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_IMAGEDRAWABLE_H

#include "Drawable.h"
#include <memory>

class ImageDrawable : public Drawable {
private:

    /// The graphics bitmap we use
    wxGraphicsBitmap mBitmap;

protected:
    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

    wxPoint mCenter = wxPoint(0, 0);

public:
    /** Default constructor disabled*/
    ImageDrawable() = delete;

    /** Copy constructor disabled*/
    ImageDrawable(const ImageDrawable&) = delete;

    /** Assignment operator disabled */
    void operator=(const ImageDrawable&) = delete;

    ImageDrawable(const std::wstring& name, const std::wstring& filename);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    bool HitTest(wxPoint pos);

    /**
     * Set the center position
     * @param pos The new center
     */
     void SetCenter(wxPoint pos) { mCenter = pos; }

     /**
      * Get the center position
      * @return The center position
      */
      wxPoint GetCenter() const { return mCenter; }
};

#endif //CANADIANEXPERIENCE_IMAGEDRAWABLE_H
