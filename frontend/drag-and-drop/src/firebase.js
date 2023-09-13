// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
import {
  collection,
  addDoc,
  getDocs,
  getFirestore,
  setDoc,
  getDoc,
  doc,
} from "firebase/firestore";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyAz3JybXxE6QR4LvZ7gLR6V_Tw8njtHx28",
  authDomain: "stereoscopictest.firebaseapp.com",
  projectId: "stereoscopictest",
  storageBucket: "stereoscopictest.appspot.com",
  messagingSenderId: "433366269314",
  appId: "1:433366269314:web:f3f92e0d1bda92ba14639b",
  measurementId: "G-JXEJGZ37XH",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);

// Initialize Cloud Firestore and get a reference to the service
const db = getFirestore(app);

export { collection, addDoc, getDocs, setDoc, getDoc, doc, db };
