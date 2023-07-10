import IPlatform from "../platforms/IPlatform";
import Live from "./Live";

export default class AdvancedLive extends Live {
    constructor(platform: IPlatform) {
        super(platform);
    }

    subtitles(): void {
        console.log("Legendas ativas");
    }
    comments(): void {
        console.log("Comentários ativos");
    }
}