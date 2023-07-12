import IConsole from "./consoles/IConsole";
import Playstation from "./consoles/Playstation";
import XBox from "./consoles/XBox";
import AdvancedPlay from "./play/AdvancedPlay";
import Play from "./play/Play";

function play_advanced(c: IConsole) {
    const p = new AdvancedPlay(c)
    p.playing();
    p.challenge();
    p.result();
}

play_advanced(new Playstation());
play_advanced(new XBox());