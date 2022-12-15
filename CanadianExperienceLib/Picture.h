/**
 * @file Picture.h
 * @author joeyv
 *
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */

#ifndef CANADIANEXPERIENCE_PICTURE_H
#define CANADIANEXPERIENCE_PICTURE_H

#include <vector>

class PictureObserver;
class Actor;

class Picture {
private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);

    /// The observers of this picture
    std::vector<PictureObserver *> mObservers;

    /// The actors in drawing order
    std::vector<std::shared_ptr<Actor>> mActors;
public:
    /**
     * Constructor
     */
    Picture() {}

    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

    /**
     * Get the picture size
     * @return Picture size in pixels
     */
    wxSize GetSize() {return mSize;}

    /**
     * Set the picture size
     * @param size Picture size in pixels
     */
    void SetSize(wxSize size) {mSize = size;}

    void AddObserver(PictureObserver *observer);
    void RemoveObserver(PictureObserver *observer);
    void UpdateObservers();
    void AddActor(std::shared_ptr<Actor> actor);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    class Iter
    {
    public:
        /**
         * Constructor
         * @param picture The picture we are iterating over
         * @param pos The position to be placed
         */
        Iter(Picture* picture, int pos) : mPicture(picture), mPos(pos){}

        /** Test for end of the iterator
         * @param other Other iterator to be compared to
         * @return true If this position equals not equal to the other position
         */
         bool operator!=(const Iter& other) const
        {
             return mPos != other.mPos;
        }

        /** Get value at current position
         * @returns Value at mPos in the collection */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Picture* mPicture;   ///< Picture we are iterating over
        int mPos;       ///< Position in the collection

    };

    /** Get an iterator for the beginning of the collection
     * @return Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
     * @return Iter object at position past the end */
    Iter end() { return Iter(this, mActors.size()); }

};

#endif //CANADIANEXPERIENCE_PICTURE_H
