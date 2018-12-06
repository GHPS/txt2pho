/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(LEXEMNODE_HEADER)
#define LEXEMNODE_HEADER

#ifndef _Windows
    #undef min
    #undef max
    #include <vector>
#else
    #include <classlib/arrays.h>
#endif

#include "lexem.h"


////////////////////////////////////////////////////////////////////////////////////////

class TLexemNode;


////////////////////////////////////////////////////////////////////////////////////////

typedef TLexemNode* TLexemNodePtr;
typedef TLexemNode* TLexemNodePointer;

#ifndef _Windows
    typedef vector<TLexemNodePointer> TLexemNodePointers;
#else
    typedef TArrayAsVector<TLexemNodePtr> TLexemNodes;
#endif


////////////////////////////////////////////////////////////////////////////////////////

class TLexemNode
{
    public:
        #ifndef _Windows
        typedef TLexemNodePointers::pointer pointer;
        typedef TLexemNodePointers::iterator iterator;
        typedef TLexemNodePointers::const_iterator const_iterator;
        typedef TLexemNodePointers::reference reference;
        typedef TLexemNodePointers::size_type size_type;
        typedef TLexemNodePointers::difference_type difference_type;
        #endif

    private:
        TLexem head;
        TLexem rest;
        #ifndef _Windows
        TLexemNodePointers children;
        #else
        TLexemNodes children;
        #endif

    public:
        TLexemNode ();
        TLexemNode (const TLexemNode &node);
        TLexemNode (const TLexem &h, const TLexem &r);

        virtual ~TLexemNode ();

        TLexemNode &operator= (const TLexemNode &node);

        inline void SetHead (const TLexem &h);
        inline void SetRest (const TLexem &r);

        inline const TLexem &Head () const;
        inline const TLexem &Rest () const;

        #ifdef _Windows
        inline const TLexemNodes &Children () const;
        inline TLexemNodePointer Children (size_t i) const;
        inline int Add (const TLexemNodePointer &node);
        inline void erase (int i);
        inline void RemoveEntry (int i);
        inline int LowerBound () const;
        inline int UpperBound () const;
        inline unsigned GetItemsInContainer() const;
        #else
        inline const TLexemNodePointers &Children () const;
        void insert (TLexemNodePointer node)
        {
            children.insert(children.end(), node);
        }
        void erase (iterator pos)
        {
            children.erase(pos);
        }
        iterator begin ()
        {
            return children.begin();
        }
        const_iterator begin () const
        {
            return children.begin();
        }
        iterator end ()
        {
            return children.end();
        }
        const_iterator end () const
        {
            return children.end();
        }
        unsigned size () const
        {
            return children.size();
        }
        #endif

        int score ;
        int penalty ;

        bool is_unwanted ();
        #ifdef _Windows
        inline
        #endif
        bool is_empty () const
        #ifndef _Windows
        {
            return size() == 0;
        }
        #else
        ;
        #endif
};


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexemNode::SetHead (const TLexem &h)
{
    head = h;
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexemNode::SetRest (const TLexem &r)
{
    rest = r;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TLexem &TLexemNode::Head () const
{
    return head;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TLexem &TLexemNode::Rest () const
{
    return rest;
}


////////////////////////////////////////////////////////////////////////////////////////

#ifndef _Windows
    inline const TLexemNodePointers &TLexemNode::Children () const
#else
    inline const TLexemNodes &TLexemNode::Children () const
#endif
{
    return children;
}


#ifdef _Windows
////////////////////////////////////////////////////////////////////////////////////////

inline TLexemNodePointer TLexemNode::Children (size_t i) const
{
//	assert(i < size());
    return children[i];
}


////////////////////////////////////////////////////////////////////////////////////////

inline int TLexemNode::Add (const TLexemNodePtr &node)
{
    return children.Add(node);
}

inline void TLexemNode::RemoveEntry (int i)
{
    children.RemoveEntry(i);
}


////////////////////////////////////////////////////////////////////////////////////////

inline int TLexemNode::LowerBound () const
{
    return children.LowerBound();
}


////////////////////////////////////////////////////////////////////////////////////////

inline int TLexemNode::UpperBound () const
{
    return children.UpperBound();
}


////////////////////////////////////////////////////////////////////////////////////////

inline unsigned TLexemNode::GetItemsInContainer() const
{
    return children.GetItemsInContainer();
}


////////////////////////////////////////////////////////////////////////////////////////

inline bool TLexemNode::is_empty () const
{
    return (GetItemsInContainer() == 0) ? true : false;
}



////////////////////////////////////////////////////////////////////////////////////////
/*
    inline void TLexemNode::erase (int i)
    {
	children.erase(&children[i]);
    }


    ////////////////////////////////////////////////////////////////////////////////////////

    inline unsigned TLexemNode::size () const
    {
	return children.size();
    }
*/

#endif
////////////////////////////////////////////////////////////////////////////////////////


TLexem get_best_decomposition (TLexemNodePointer root, int &, int &);


#endif // LEXEMNODE_HEADER
