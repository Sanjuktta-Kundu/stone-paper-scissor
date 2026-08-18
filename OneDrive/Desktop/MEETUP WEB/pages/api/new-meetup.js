import { MongoClient } from "mongodb";

// /api/new-meetup

async function handler(req, res) {
 if (req.method === 'POST') {
    const data = req.body;

    const { title, image, address, description } = data; 

    const client = await MongoClient.connect('mongodb+srv://sanjukttakundu51_db_user:sanjuktta225@cluster0.k9snvdg.mongodb.net/?appName=Cluster0');
    const db = client.db();

    const meetupsCollection = db.collection('meetups');

    const result = await meetupsCollection.insertOne(data);
    console.log(result);

    client.close();

    res.status(201).json({message: 'Meetup inserted!'});
 } else {
    res.status(405).json({message: 'Method not allowed'});
 }
}
export default handler;