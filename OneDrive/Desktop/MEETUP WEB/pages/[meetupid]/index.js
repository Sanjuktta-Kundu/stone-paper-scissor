import MeetupDetails from "../../components/meetups/MeetupDetails";
function MeetupDetailsPage(props) {
    return (
        <MeetupDetails 
        image={props.meetupData.image}
        title={props.meetupData.title}
        address={props.meetupData.address}
        description={props.meetupData.description}
         />
        
    );
}

export async function getStaticPaths() {
    return {
        fallback: false,
        paths: [
          { 
             params: {
            meetupid: 'm1',
            },
         },
         { 
             params: {
            meetupid: 'm2',
            },
         },
        ],
    };
}
export async function getStaticProps(context) {
// fetch data for a single meetup

const meetupId = context.params.meetupid;
console.log(meetupId);

const meetupData = {
    m1: {
        id: 'm1',
        title: "First Meetup",
        image: 'https://images.unsplash.com/photo-1477959858617-67f85cf4f1df?auto=format&fit=crop&w=800&q=80',
        address: "Some Street 5, Some City", 
        description: "This is a first meetup!"
    },
    m2: {
        id: 'm2',
        title: "A Second Meetup",
        image: 'https://images.unsplash.com/photo-1464822759023-fed622ff2c3b?auto=format&fit=crop&w=800&q=80',
        address: "Some other address 10, 54321 Another City",
        description: "This is our second meetup for the community!"
    }
};

return{
    props: {
        meetupData: meetupData[meetupId] || meetupData.m1
    },
};
}

export default MeetupDetailsPage;