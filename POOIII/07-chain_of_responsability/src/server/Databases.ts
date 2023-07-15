import PermissionType from "./PermissionType";

interface DatabaseItem {
    email: string;
    password: string;
    permission: PermissionType;
}

const Database: DatabaseItem[] = [
    {
        email: "admin1@hotmail.com",
        password: "1234",
        permission: PermissionType.ADMIN,
    },
    {
        email: "user1@hotmail.com",
        password: "1234",
        permission: PermissionType.USER,
    },
    {
        email: "user2@hotmail.com",
        password: "1234",
        permission: PermissionType.USER,
    },
    {
        email: "admin2@hotmail.com",
        password: "1234",
        permission: PermissionType.USER,
    },
];

export default Database;