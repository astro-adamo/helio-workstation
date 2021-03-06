/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "CommandPaletteActionsProvider.h"

class PianoRoll;
class ChordCompiler;

class CommandPaletteChordConstructor final : public CommandPaletteActionsProvider
{
public:

    CommandPaletteChordConstructor(PianoRoll &roll);
    ~CommandPaletteChordConstructor() override;

    bool usesPrefix(const Prefix prefix) const noexcept override
    {
        return prefix == '!';
    }

    void updateFilter(const String &pattern, bool skipPrefix) override;
    void clearFilter() override;

protected:

    const Actions &getActions() const override;
    mutable Actions actions;

private:

    const UniquePointer<ChordCompiler> chordCompiler;

    PianoRoll &roll;
    Array<int> chord;

    bool hasMadeChanges = false;
    void undoIfNeeded();
    void previewIfNeeded();

};
