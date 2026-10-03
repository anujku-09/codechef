  const bio = "Frontend Developer | React Enthusiast | CodeChef User";

  return (
    <div>

      <h1 style={{ textAlign: "center", fontFamily: "Arial, sans-serif" }}>
        Profile Card
      </h1>

      {/* Render the ProfileCard component with user details */}
      <ProfileCard name = {name} bio = {bio} avatarUrl={avatarUrl} />

    </div>
  );
  const name = "John Doe";
  // update the user name and bio

};
  const avatarUrl = "https://cdn.codechef.com/images/problems/PREACT018/a29545c678c75e59bc684868407b1d13.webp";
const App = () => {
// Update the App component - Renders the ProfileCard component
