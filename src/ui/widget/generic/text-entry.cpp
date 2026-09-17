// SPDX-License-Identifier: GPL-2.0-or-later

#include "text-entry.h"

namespace Inkscape::UI::Widget {

void TextEntry::construct()
{
    set_name("TextEntry");

    signal_activate().connect([this] {
        _signal_commit.emit();
    });
    property_has_focus().signal_changed().connect([this] {
        if (!has_focus()) {
            _signal_commit.emit();
        }
    });
}

TextEntry::TextEntry()
    : Glib::ObjectBase("TextEntry")
{
    construct();
}

TextEntry::TextEntry(GtkEntry* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
    : Glib::ObjectBase("TextEntry")
    , BuildableWidget(cobject, builder)
{
    construct();
}

} // namespace Inkscape::UI::Widget
