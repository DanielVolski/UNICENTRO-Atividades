import IPlatform from "./platforms/IPlatform";
import Twitch from "./platforms/Twitch";
import Youtube from "./platforms/Youtube";
import Facebook from "./platforms/Facebook";
import Live from "./transmissions/Live";
import AdvancedLive from "./transmissions/AdvancedLive";

function start_live(platform: IPlatform) {
    console.log("Aguarde...");
    const live = new Live(platform);
    live.broadcasting();
    live.result();
}

function start_advanced_live(platform: IPlatform) {
    console.log("Aguarde...");
    const live = new AdvancedLive(platform);
    live.broadcasting();
    live.result();
    live.subtitles();
    live.comments();
}

start_advanced_live(new Youtube());
start_advanced_live(new Twitch());
start_advanced_live(new Facebook());