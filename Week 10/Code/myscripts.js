// Initialize Firestore through Firebase
var firebaseConfig = {
    apiKey: "AIzaSyDlwoDDJ9cDMdVRlojb1AobSOGBIT3QF4g",
    authDomain: "infinite-bruin-349007.firebaseapp.com",
    projectId: "infinite-bruin-349007",
    storageBucket: "infinite-bruin-349007.appspot.com",
    messagingSenderId: "344525732876",
    appId: "1:344525732876:web:8ae3770733353cfce34229",
    measurementId: "G-X3Z2ZY8BX4"
    };
    // Initialize Firebase
    firebase.initializeApp(firebaseConfig);
    var db = firebase.firestore();

    // Get a live data snapshot (i.e. auto-refresh) of our Reviews collection
db.collection("Reviews").onSnapshot((querySnapshot) => {
    // Empty HTML table
    $('#reviewList').empty();
    // Loop through snapshot data and add to HTML table
    querySnapshot.forEach((doc) => {
    $('#reviewList').append('<tr>');
    $('#reviewList').append('<td>' + doc.data().book_name + '</td>');
    $('#reviewList').append('<td>' + doc.data().book_rating + '/5</td>');
    $('#reviewList').append('</tr>');
    });
    // Display review count
    $('#mainTitle').html(querySnapshot.size + " book reviews in the list");
    });

// Add button pressed
$("#addButton").click(function() {
    // Add review to Firestore collection
    db.collection("Reviews").add({
    book_name: $("#bookName").val(),
    book_rating: parseInt($("#bookRating").val())
    })
    .then((docRef) => {
    console.log("Document written with ID: ", docRef.id);
    })
    .catch((error) => {
    console.error("Error adding document: ", error);
    });
    // Reset form
    $("#bookName").val('');
    $("#bookRating").val('1');
    });