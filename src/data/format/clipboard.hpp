//+----------------------------------------------------------------------------+
//| Description:  Magic Set Editor - Program to make Magic (tm) cards          |
//| Copyright:    (C) Twan van Laarhoven and the other MSE developers          |
//| License:      GNU General Public License 2 or later (see file COPYING)     |
//+----------------------------------------------------------------------------+

#pragma once

// ----------------------------------------------------------------------------- : Includes

#include <util/prec.hpp>
#include <wx/dataobj.h>

DECLARE_POINTER_TYPE(Set);
DECLARE_POINTER_TYPE(Card);
DECLARE_POINTER_TYPE(Keyword);

// ----------------------------------------------------------------------------- : CardDataObject

/// The data format for cards on the clipboard
class CardsDataObject : public wxTextDataObject {
public:
  /// Name of the format of MSE cards
  static wxDataFormat format;
  
  CardsDataObject();
  /// Store a card
  CardsDataObject(const SetP& set, const vector<CardP>& cards);
  
  /// Retrieve the cards, only if it is made with the same game as set
  /** Return true if the cards are correctly retrieved, and there is at least one card */
  bool getCards(const SetP& set, vector<CardP>& out);
  size_t GetDataSize(const wxDataFormat& format) const override;
};

// ----------------------------------------------------------------------------- : KeywordDataObject

/// The data format for keywords on the clipboard
class KeywordDataObject : public wxTextDataObject {
public:
  /// Name of the format of MSE keywords
  static wxDataFormat format;
  
  KeywordDataObject();
  /// Store a keyword
  KeywordDataObject(const SetP& set, const KeywordP& card);
  
  /// Retrieve a keyword, only if it is made with the same game as set
  KeywordP getKeyword(const SetP& set);
  size_t GetDataSize(const wxDataFormat& format) const override;
};

// ----------------------------------------------------------------------------- : Card on clipboard

/// A DataObject for putting one or more cards on the clipboard, in multiple formats
class CardsOnClipboard : public wxDataObjectComposite {
public:
  CardsOnClipboard(const SetP& set, const vector<CardP>& cards);
};

