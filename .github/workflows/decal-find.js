module.exports = async ({github, context}) => {
    const {owner, repo} = context.repo;
    const pull_number = context.issue.number;

    const {status, data: pr} = await github.rest.pulls.listFiles({owner, repo, pull_number});
    if (status !== 200) {
        throw new Error(`Failed to fetch PR: ${pull_number}`);
    }

    const svcReachable = [
        "cmd/",
        "array2d",
    ]

    for (let i in pr) {
        for (let j in svcReachable) {
            if (pr[i].filename.includes(svcReachable[j])) {
                return true
            }
        }
    }

    return false
}
