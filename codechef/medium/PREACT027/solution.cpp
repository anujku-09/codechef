import styles from './Notification.module.css';

export function Notification({ message }) {
  return (
    <div className={styles.notification}>
  );
}

function App() {
  return (
    <div>
      <Notification message="Success! Your changes have been saved." />
      <Notification message="File uploaded successfully!" />
    </div>
  );
}

export default App;
      {message}
    </div>

